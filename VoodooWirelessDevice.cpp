/*
 *  VoodooWirelessDevice.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 12/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#pragma mark Defines and other stuff

#include "VoodooWirelessDevice.h"
#include "VoodooWirelessCommand.h"

#include <libkern/c++/OSData.h>
#include <libkern/c++/OSSymbol.h>
#include <sys/sysctl.h>

#define MyClass			VoodooWirelessDevice
#define super			IO80211Controller
#define IOCTL_GET_REQ		3223611849 // magic number alert!
#define IOC_STRUCT_RET(type)	type* ret = (type*) data; ret->version = APPLE80211_VERSION;
#define IOC_STRUCT_GOT(type)	type* got = (type*) data;
#define toMbps(x)		(((x) & 0x7f) / 2)

OSDefineMetaClassAndStructors(VoodooWirelessDevice, IO80211Controller)

SYSCTL_UINT(_debug, OID_AUTO, voodoowireless, CTLFLAG_RW, &org_voodoo_wireless_debug, 0, "VoodooWireless driver debug output level");

enum {
	// Flags for _flags member variable
	flagResourcesAllocated	= 1,
	flagPowerOn		= 2,
	flagInterfaceEnabled	= 4,
	flagScanning		= 8,
	flagAssociating		= 16
};

enum {
	staInit,
	staAuthenticated,
	staAssociated
};

#define MAX_SCAN_RESULTS 64

//*********************************************************************************************************************
#pragma mark -
#pragma mark Basic IOKit functions
//*********************************************************************************************************************
bool
MyClass::start
( IOService* provider )
{
	if (!super::start(provider))
		return false;
	
	sysctl_register_oid(&sysctl__debug_voodoowireless);
	
	/* Allocate a lock for ::enable() and ::disable() */
	_lock = IOLockAlloc();
	if (_lock == 0)
		return false;
	
	/* Retain a reference to superclass's workloop */
	_workloop = OSDynamicCast(IO80211WorkLoop, getWorkLoop());
	_workloop->retain();
	
	/* Create the command pool for queueing HW subroutines */
	_commandPool = IOCommandPool::withWorkLoop(_workloop);
	
	/* Create the array to hold scan results */
	_scanResults = OSArray::withCapacity(32); // by default, but it autoexpands
	
	/* Do HW specific initialization */
	if (allocateResources(provider) != kIOReturnSuccess) {
		DBG(dbgFatal, "Could not allocate hardware resources!\n");
		return false;
	} else {
		_flags |= flagResourcesAllocated;
	}
	
	OSObject* cipher = waitForService(propertyMatching(OSSymbol::withCStringNoCopy(CIPHER_PROPERTY_NAME),
							   OSString::withCStringNoCopy("WEP")));	
	if (!cipher) {
		DBG(dbgWarning, "No WEP cipher found, WEP connections may not work\n");
	} else {
		_cipher = OSDynamicCast(VoodooWirelessCipher, cipher);
		_cipher->retain();
		DBG(dbgInfo, "WEP cipher found and retained.\n");
	}
	
	/* Get some basic info about this hardware */
	getHardwareInfo(&_hwInfo);
	
	/* Tell the system what kind of media we support */
	OSDictionary* mediumDict = OSDictionary::withCapacity(1);
	uint32_t maxSpeed = 0;
	
	if (_hwInfo.supportedModes & IEEE::dot11B)
		maxSpeed = 11000000;
	
	if (_hwInfo.supportedModes & IEEE::dot11A || _hwInfo.supportedModes & IEEE::dot11G)
		maxSpeed = 54000000;
	
	if (_hwInfo.supportedModes & IEEE::dot11N)
		maxSpeed = 300000000;
	
	_medium = IONetworkMedium::medium(kIOMediumIEEE80211Auto, maxSpeed, kIOMediumOptionHalfDuplex);
	IONetworkMedium::addMedium(mediumDict, _medium);
	publishMediumDictionary(mediumDict);
	setSelectedMedium(_medium);
	
	/* HW resources are allocated, we can attach the interface now */
	if (!attachInterface((IONetworkInterface**) &_netif, /* attach to DLIL = */ true)) {
		DBG(dbgFatal, "Could not attach wireless interface!\n");
		return false;
	}
	
	/* Attach to bpf for tcpdump of raw 802.11 packets */
	_netif->bpfAttach(/* DLT	 = */ 105,
			  /* Header size = */ 30);
	
	/* Start the worker thread
	IOCreateThread(OSMemberFunctionCast(IOThreadFunc, this, &VoodooWirelessDevice::workerThread), 0);
	*/
	
	/* And finally register this service */
	registerService();
	
	return true;
}


void
MyClass::stop
( IOService* provider )
{
	//enqueueCommand(VoodooWirelessCommand::cmdExitThread);
	
	if (_cipher) {
		_cipher->freeContext(_cipherContext);
		_cipherContext = 0;
		_cipher->release();
		_cipher = 0;
	}
	
	freeResources(provider);
	_flags &= ~(flagResourcesAllocated);
	
	if (_lock)
		IOLockFree(_lock);
	
	/* This caused KP on unload so let this memory leak
	RELEASE(_hwInfo.manufacturer);
	RELEASE(_hwInfo.model);
	RELEASE(_hwInfo.hardwareRevision);
	RELEASE(_hwInfo.driverVersion);
	RELEASE(_hwInfo.firmwareVersion);
	 */
	RELEASE(_scanResults);
	RELEASE(_queue);
	RELEASE(_netif);
	RELEASE(_medium);
	RELEASE(_commandPool);
	RELEASE(_workloop);
	
	sysctl_unregister_oid(&sysctl__debug_voodoowireless);
	
	return super::stop(provider);
}


// Power Management
IOReturn
MyClass::registerWithPolicyMaker
( IOService* policyMaker )
{
	static IOPMPowerState powerStateArray[ 2 ] = {
		{ 1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,kIOPMDeviceUsable,kIOPMPowerOn,kIOPMPowerOn,0,0,0,0,0,0,0,0 }
	};
	return policyMaker->registerPowerDriver( this, powerStateArray, 2 );
}


//*********************************************************************************************************************
#pragma mark -
#pragma mark Apple 802.11 ioctl
//*********************************************************************************************************************
SInt32
MyClass::apple80211Request
( UInt32 request_type, int request_number, IO80211Interface* interface, void* data )
{
	DBG(dbgInfo, "Airport request %u (%s %u)\n", request_type, (request_type == IOCTL_GET_REQ) ? "GET" : "SET", request_number);
	if (request_type == IOCTL_GET_REQ)
		return apple80211Request_GET(request_number, data);
	else
		return apple80211Request_SET(request_number, data);
}


IOReturn
MyClass::enqueueCommand
( uint32_t cmdType, void* arg0, void* arg1 )
{
	VoodooWirelessCommand* cmd = VoodooWirelessCommand::withType((VoodooWirelessCommand::CommandType) cmdType,
								     arg0, arg1);
	if (!cmd)
		return kIOReturnError;
	_commandPool->returnCommand(cmd);
	return kIOReturnSuccess;
}


IOReturn
MyClass::apple80211Request_SET
( int request_number, void* data )
{
	int i;
	switch (request_number)
	{
		case APPLE80211_IOC_POWER:
		{
			IOC_STRUCT_GOT(apple80211_power_data);
			switch (got->power_state[0]) {
				case APPLE80211_POWER_ON:
					DBG(dbgInfo, "Setting power on\n");
					if (_flags & flagPowerOn) // already on
						return kIOReturnError;
					else {
						if (turnPowerOn() == kIOReturnSuccess) {
							setPowerOn();
							return kIOReturnSuccess;
						} else
							return kIOReturnError;
					}
					
				case APPLE80211_POWER_OFF:
					DBG(dbgInfo, "Setting power off\n");
					if (!(_flags & flagPowerOn)) // already off
						return kIOReturnError;
					else {
						if (turnPowerOff() == kIOReturnSuccess) {
							setPowerOff();
							return kIOReturnSuccess;
						} else
							return kIOReturnError;
					}
					
				default:
					return kIOReturnError;
			};
		}
			
		case APPLE80211_IOC_SCAN_REQ:
		{
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
			{
				DBG(dbgWarning, "Scan not started because hardware was busy\n");
				return kIOReturnBusy;
			}
			
			IOC_STRUCT_GOT(apple80211_scan_data);
			
			if (got->scan_type == APPLE80211_SCAN_TYPE_FAST) // return cached results
				return kIOReturnSuccess; // no problem, we have it stored
			
			// Prepare parameters
			ScanParameters scan;
			bzero(&scan, sizeof(scan));
			scan.scanType		= (ScanParameters::ScanType) got->scan_type;
			scan.scanPhyMode	= (IEEE::PHYModes) got->phy_mode;
			scan.dwellTime		= (got->dwell_time == 0) ? 200 : got->dwell_time;
			scan.restTime		= (got->rest_time  == 0) ?  50 : got->rest_time;
			bcopy(&got->bssid, &scan.bssid, 6);
			if (got->ssid_len != 0)
				scan.ssid = OSData::withBytesNoCopy((char*) got->ssid, got->ssid_len);
			else
				scan.ssid = OSData::withCapacity(0);
			_totalResultsInCurrentScan = 0;
			
			if (startScan(&scan, &_hwInfo.supportedChannels) != kIOReturnSuccess)
			{
				DBG(dbgWarning, "CMD: Start scan command failed\n");
				return kIOReturnError;
			} else {
				// scan has started, clear existing results in anticipation of new ones
				_scanResults->flushCollection();
				_flags |= flagScanning;
				DBG(dbgInfo, "CMD: Start scan command completed\n");
				return kIOReturnSuccess;
			}
		}
			
		case APPLE80211_IOC_ASSOCIATE:
		{
			// Don't try to associate if already associated,
			// or in process of associating or scanning
			if ((_staState == staAssociated) ||
			    (_flags & flagAssociating))
			{
				DBG(dbgWarning, "Can't associate, already associated or assoc in progress\n");
				return kIOReturnBusy;
			}
			
			// If we are scanning, abort it before associating
			if (_flags & flagScanning) {
				DBG(dbgWarning, "Assoc request during scan. Aborting scan first\n");
				abortScan();
				report(msgScanAborted);
			}
			
			// Prepare assoc params and enqueue the command
			IOC_STRUCT_GOT(apple80211_assoc_data);
			
			apple80211_scan_result* sr = findScanResult(got);
			if (sr == 0) // no network with given params were found
				return kIOReturnError;
			
			AssociationParameters params;
			bzero(&params, sizeof(params));
			
			bcopy(sr->asr_bssid, &params.bssid, 6);
			params.ssid		= OSData::withBytes(sr->asr_ssid, sr->asr_ssid_len);
			params.channel.number	= sr->asr_channel.channel;
			params.channel.flags	= sr->asr_channel.flags;
			params.capability.value	= sr->asr_cap;
			
			params.supportedRates.numItems = sr->asr_nrates;
			for (i = 0; i < sr->asr_nrates; i++)
				params.supportedRates.rate[i] = (IEEE::DataRate) sr->asr_rates[i];
			
			params.beaconInterval	= sr->asr_beacon_int;
			params.noiseLevel	= -90; // XXX
			params.signalLevel	= sr->asr_rssi;
			params.connectionMode	= (AssociationParameters::APMode) got->ad_mode;
			
			params.authType	= (AssociationParameters::AuthType)
						((got->ad_auth_upper * 2) | (got->ad_auth_lower - 1)); // XXX!!
			
			if (got->ad_flags & APPLE80211_ASSOC_F_CLOSED)
				params.closedNetwork = true;
			
			/* Set the WEP key if any */
			if (got->ad_key.key_cipher_type == APPLE80211_CIPHER_WEP_40 ||
			    got->ad_key.key_cipher_type == APPLE80211_CIPHER_WEP_104)
			{
				params.wepKey.length	= got->ad_key.key_len;
				params.wepKey.index	= got->ad_key.key_index;
				bcopy(got->ad_key.key, params.wepKey.key, params.wepKey.length);
			} else {
				params.wepKey.length	= 0;
			}
			
			// Save assoc and network for later use
			bcopy(got, &_currentAssocData, sizeof(*got));
			bcopy(&params.bssid, &_currentAssocData.ad_bssid, 6); // apple sends the bssid usually zeroed
			bcopy(sr,  &_currentNetwork,   sizeof(*sr));
			
			// Now enqueue the command
			if (associate(&params) != kIOReturnSuccess) {
				DBG(dbgWarning, "CMD: Association command failed\n");
				return kIOReturnError;
			} else {
				_flags |= flagAssociating;
				_staState = staInit;
				DBG(dbgInfo, "CMD: Association command completed\n");
				return kIOReturnSuccess;
			}
		}
		
		case APPLE80211_IOC_TXPOWER:
			return kIOReturnSuccess; // TODO !!
		
		case APPLE80211_IOC_RSN_IE:
			return kIOReturnUnsupported; // TODO !!
		
		case APPLE80211_IOC_FRAG_THRESHOLD:
		{
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
			    return kIOReturnBusy;
			IOC_STRUCT_GOT(apple80211_frag_threshold_data);
			return setConfiguration(configFragmentationThreshold, &got->threshold);
		}
		
		case APPLE80211_IOC_PROTMODE:
		{
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
				return kIOReturnBusy;
			IOC_STRUCT_GOT(apple80211_protmode_data);
			if (got->protmode == APPLE80211_PROTMODE_OFF)
				got->threshold = 2346; // max threshold == turns it off
			return setConfiguration(configRTSThreshold, &got->threshold);
		}
		
		case APPLE80211_IOC_DISASSOCIATE:
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
				return kIOReturnBusy;			
			if (disassociate() != kIOReturnSuccess) {
				DBG(dbgWarning, "Disassociation failed\n");
				return kIOReturnError;
			} else {
				DBG(dbgInfo, "Disassociated\n");
				_staState = staInit;
				_flags &= ~(flagAssociating);
				return kIOReturnSuccess;
			}

		case APPLE80211_IOC_SHORT_RETRY_LIMIT:
		{
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
				return kIOReturnBusy;			
			IOC_STRUCT_GOT(apple80211_retry_limit_data);
			return setConfiguration(configShortRetryLimit, &got->limit);
		}
			
		case APPLE80211_IOC_LONG_RETRY_LIMIT:
		{
			if ((_flags & flagScanning) ||
			    (_flags & flagAssociating))
				return kIOReturnBusy;			
			IOC_STRUCT_GOT(apple80211_retry_limit_data);
			return setConfiguration(configLongRetryLimit, &got->limit);
		}
			
		default:
			return kIOReturnUnsupported;
	};
}



IOReturn
MyClass::apple80211Request_GET
( int request_number, void* data )
{
	switch (request_number)
	{
		case APPLE80211_IOC_CARD_CAPABILITIES:
		{
			IOC_STRUCT_RET(apple80211_capability_data);
			
			uint32_t caps;
			
			if (_hwInfo.capabilities.WEP)		caps |= APPLE80211_CAP_WEP;
			if (_hwInfo.capabilities.TKIP)		caps |= APPLE80211_CAP_TKIP;
			if (_hwInfo.capabilities.AES_CCMP)	caps |= APPLE80211_CAP_AES_CCM;
			if (_hwInfo.capabilities.WPA1)		caps |= APPLE80211_CAP_WPA1;
			if (_hwInfo.capabilities.WPA2)		caps |= APPLE80211_CAP_WPA2;
			
			if (_hwInfo.capabilities.WPA1 &&
			    _hwInfo.capabilities.WPA2)		caps |= APPLE80211_CAP_WPA;
			
			if (_hwInfo.capabilities.AdHocMode)	caps |= APPLE80211_CAP_IBSS;
			if (_hwInfo.capabilities.HostAPMode)	caps |= APPLE80211_CAP_HOSTAP;
			if (_hwInfo.capabilities.MonitorMode)	caps |= APPLE80211_CAP_MONITOR;
			
			if (_hwInfo.capabilities.PowerManagement)	caps |= APPLE80211_CAP_PMGT;
			if (_hwInfo.capabilities.TxPowerManagement)	caps |= APPLE80211_CAP_TXPMGT;
			if (_hwInfo.capabilities.WakeOnWireless)	caps |= APPLE80211_CAP_WOW;
			
			if (_hwInfo.capabilities.ShortSlot)	caps |= APPLE80211_CAP_SHSLOT;
			if (_hwInfo.capabilities.ShortPreamble)	caps |= APPLE80211_CAP_SHPREAMBLE;
			if (_hwInfo.capabilities.FrameBursting)	caps |= APPLE80211_CAP_BURST;
			if (_hwInfo.capabilities.WMEQoS)	caps |= APPLE80211_CAP_WME;
			if (_hwInfo.capabilities.ShortGuardInterval20MHz)	caps |= APPLE80211_CAP_SHORT_GI_20MHZ;
			if (_hwInfo.capabilities.ShortGuardInterval40MHz)	caps |= APPLE80211_CAP_SHORT_GI_40MHZ;
			
			ret->capabilities[0] = (caps & 0xff);
			ret->capabilities[1] = (caps & 0xff00) >> 8;
			ret->capabilities[2] = (caps & 0xff0000) >> 16;
			
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_STATUS_DEV_NAME:
		{
			IOC_STRUCT_RET(apple80211_status_dev_data);
			strncpy((char*) ret->dev_name, "voodoowireless", sizeof("voodoowireless"));
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_DRIVER_VERSION:
		{
			IOC_STRUCT_RET(apple80211_version_data);
			ret->string_len = _hwInfo.driverVersion->getLength();
			strncpy(ret->string, _hwInfo.driverVersion->getCStringNoCopy(), ret->string_len);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_HARDWARE_VERSION:
		{
			IOC_STRUCT_RET(apple80211_version_data);
			ret->string_len = _hwInfo.hardwareRevision->getLength();
			strncpy(ret->string, _hwInfo.hardwareRevision->getCStringNoCopy(), ret->string_len);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_COUNTRY_CODE:
		{
			IOC_STRUCT_RET(apple80211_country_code_data);
			strncpy((char*) ret->cc, "IN ", sizeof("IN ")); // FIXME
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_LOCALE:
		{
			IOC_STRUCT_RET(apple80211_locale_data);
			ret->locale = APPLE80211_LOCALE_APAC; // FIXME
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_POWERSAVE:
		{
			IOC_STRUCT_RET(apple80211_powersave_data);
			ret->powersave_level = APPLE80211_POWERSAVE_MODE_DISABLED; // FIXME
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_TXPOWER:
		{
			IOC_STRUCT_RET(apple80211_txpower_data);
			ret->txpower_unit = APPLE80211_UNIT_DBM;
			if (getConfiguration(configTxPower, &ret->txpower) != kIOReturnSuccess)
				return kIOReturnError;
			ret->txpower = todBm(ret->txpower);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_POWER:
		{
			IOC_STRUCT_RET(apple80211_power_data);
			ret->num_radios = 1;
			ret->power_state[0] = (_flags & flagPowerOn) ? APPLE80211_POWER_ON : APPLE80211_POWER_OFF;
			return kIOReturnSuccess;
		}
			
		case APPLE80211_IOC_SSID:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_ssid_data);
			ret->ssid_len = _currentAssocData.ad_ssid_len;
			bcopy(_currentAssocData.ad_ssid, ret->ssid_bytes, ret->ssid_len);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_BSSID:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_bssid_data);
			bcopy(_currentNetwork.asr_bssid, &ret->bssid, APPLE80211_ADDR_LEN);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_CHANNEL:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_channel_data);
			ret->channel.channel = _currentNetwork.asr_channel.channel;
			ret->channel.flags   =	APPLE80211_C_FLAG_10MHZ |
						APPLE80211_C_FLAG_2GHZ |
						APPLE80211_C_FLAG_ACTIVE;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_SUPPORTED_CHANNELS:
		{
			IOC_STRUCT_RET(apple80211_sup_channel_data);
			ret->num_channels = _hwInfo.supportedChannels.numItems;
			for (int i = 0; i < ret->num_channels; i++) {
				ret->supported_channels[i].channel = _hwInfo.supportedChannels.channel[i].number;
				ret->supported_channels[i].flags   = _hwInfo.supportedChannels.channel[i].flags;
			}
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_STATE:
		{
			IOC_STRUCT_RET(apple80211_state_data);
			if (_staState == staAssociated) {
				ret->state = APPLE80211_S_RUN;
				return kIOReturnSuccess;
			}
			
			if (_flags & flagScanning) {
				ret->state = APPLE80211_S_SCAN;
				return kIOReturnSuccess;
			}
			
			if (!(_flags & flagScanning) &&
			    !(_flags & flagAssociating))
			{
				// ie. not associating and not scanning
				ret->state = APPLE80211_S_INIT;
				return kIOReturnSuccess;
			}
			
			// otherwise we're mid-assoc
			switch (_staState) {
				case staInit:
					// auth is in progress
					ret->state = APPLE80211_S_AUTH;
					break;
					
				case staAuthenticated:
					// auth'd, assoc in progress
					ret->state = APPLE80211_S_ASSOC;
					break;
				
				default:
					// should not happen, but just to silence compiler
					break;
			};
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_PHY_MODE:
		{
			IOC_STRUCT_RET(apple80211_phymode_data);
			if (_hwInfo.supportedModes & IEEE::dot11A) ret->phy_mode |= APPLE80211_MODE_11A;
			if (_hwInfo.supportedModes & IEEE::dot11B) ret->phy_mode |= APPLE80211_MODE_11B;
			if (_hwInfo.supportedModes & IEEE::dot11G) ret->phy_mode |= APPLE80211_MODE_11G;
			if (_hwInfo.supportedModes & IEEE::dot11N) ret->phy_mode |= APPLE80211_MODE_11N;
			ret->active_phy_mode = (_staState == staAssociated) ?	_currentAssocData.ad_mode :
										APPLE80211_MODE_AUTO;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_OP_MODE:
		{
			IOC_STRUCT_RET(apple80211_opmode_data);
			ret->op_mode = APPLE80211_M_STA;
			if (_hwInfo.capabilities.AdHocMode)	ret->op_mode |= APPLE80211_M_IBSS;
			if (_hwInfo.capabilities.HostAPMode)	ret->op_mode |= APPLE80211_M_HOSTAP;
			if (_hwInfo.capabilities.MonitorMode)	ret->op_mode |= APPLE80211_M_MONITOR;
			return kIOReturnSuccess;
		}
			
		case APPLE80211_IOC_NOISE:
		{
			IOC_STRUCT_RET(apple80211_noise_data);
			ret->num_radios = 1;
			ret->noise_unit = APPLE80211_UNIT_DBM;
			ret->noise[0]	= ret->aggregate_noise
					= ret->noise_ext[0]
					= ret->aggregate_noise_ext
					= _currentNoiseLevel;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_RSSI:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_rssi_data);
			ret->num_radios = 1;
			ret->rssi_unit	= APPLE80211_UNIT_DBM;
			ret->rssi[0]	= ret->aggregate_rssi
					= ret->rssi_ext[0]
					= ret->aggregate_rssi_ext
					= _currentSignalLevel;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_LAST_RX_PKT_DATA:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_last_rx_pkt_data);
			ret->rate = toMbps(_lastRxFrameHeader.rate);
			ret->rssi = todBm(_lastRxFrameHeader.signalLevel);
			ret->num_streams = 1; // only changes for 11n mode
			// TODO: we should ideally fill in ret->sa too, but ignoring for now
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_RATE:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_rate_data);
			ret->num_radios = 1;
			if (getConfiguration(configCurrentTxRate, &ret->rate[0]) != kIOReturnSuccess)
				return kIOReturnError;
			ret->rate[0] = toMbps(ret->rate[0]);
			return kIOReturnSuccess;
		}
			
		case APPLE80211_IOC_RATE_SET:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_rate_set_data);
			for (int nr = 0; nr < _currentNetwork.asr_nrates; nr++)
				ret->rates[nr].rate = toMbps(_currentNetwork.asr_rates[nr]);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_RSN_IE:
		{
			if (_currentAssocData.ad_rsn_ie_len == 0)
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_rsn_ie_data);
			ret->len = _currentAssocData.ad_rsn_ie_len;
			bcopy(_currentAssocData.ad_rsn_ie, ret->ie, ret->len);
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_FRAG_THRESHOLD:
		{
			IOC_STRUCT_RET(apple80211_frag_threshold_data);
			if (getConfiguration(configFragmentationThreshold, &ret->threshold) != kIOReturnSuccess)
				return kIOReturnError;
			else
				return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_DEAUTH:
		{
			if (_staState == staAssociated)
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_deauth_data);
			ret->deauth_reason = _lastReasonCode;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_AUTH_TYPE:
		{
			if (!(_staState == staAssociated))
				return kIOReturnError;
			IOC_STRUCT_RET(apple80211_authtype_data);
			ret->authtype_upper = _currentAssocData.ad_auth_upper;
			ret->authtype_lower = _currentAssocData.ad_auth_lower;
			return kIOReturnSuccess;
		}
		
		case APPLE80211_IOC_ASSOCIATION_STATUS:
		{
			IOC_STRUCT_RET(apple80211_assoc_status_data);
			if (_staState == staAssociated) {
				ret->status = APPLE80211_STATUS_SUCCESS;
				return kIOReturnSuccess;
			}
			if (_flags & flagAssociating)
				return kIOReturnBusy;
			else {
				ret->status = APPLE80211_STATUS_UNSPECIFIED_FAILURE; // TODO: use reason code
				return kIOReturnSuccess;
			}
		}
		
		case APPLE80211_IOC_SCAN_RESULT:
		{
			if (_flags & flagScanning)
				return kIOReturnBusy;
			if (_resultsPending <= 0) {
				DBG(dbgInfo, "Sent all scan results\n");
				_resultsPending = _scanResults->getCount(); // wrap back for later
				return -1; // XXX
			} else {
				DBG(dbgInfo, "Sending scan result no. %u\n", _scanResults->getCount());
				apple80211_scan_result** ret = (apple80211_scan_result**) data;
								
				OSObject* resultobj = _scanResults->getObject(--_resultsPending);
				if (!resultobj) { // no results - error condition
					DBG(dbgWarning, "ERR: no scan result found for index %u\n", _resultsPending);
					_resultsPending = _scanResults->getCount(); // wrap for later
					return -1;
				}
				
				OSData*	oneResult = OSDynamicCast(OSData, resultobj);
				*ret = (apple80211_scan_result*) oneResult->getBytesNoCopy();
				
				return kIOReturnSuccess;
			}
		}
		
		case APPLE80211_IOC_MCS:
		{
			IOC_STRUCT_RET(apple80211_mcs_data);
			ret->index = APPLE80211_MCS_INDEX_AUTO;
			return kIOReturnSuccess;
		}
			
		case APPLE80211_IOC_PROTMODE:
		{
			IOC_STRUCT_RET(apple80211_protmode_data);
			ret->protmode = APPLE80211_PROTMODE_AUTO;
			ret->threshold = 2346; // FIXME
			return kIOReturnSuccess;
		}
			
		case APPLE80211_IOC_INT_MIT:
		{
			IOC_STRUCT_RET(apple80211_intmit_data);
			ret->int_mit = APPLE80211_INT_MIT_AUTO;
			return kIOReturnSuccess;
		}
		
		default:
			return kIOReturnUnsupported;
	};
}



/* This function is called when the background command-queue thread starts */
void
MyClass::workerThread
(void* arg)
{
	VoodooWirelessCommand* cmd;
	bool shouldExit = false;
	DBG(dbgInfo, "Worker thread has started\n");
	
	while (!shouldExit)
	{
		/* Get one command from the queue */
		cmd = OSDynamicCast(VoodooWirelessCommand, _commandPool->getCommand(true));
		
		if (!cmd)
			continue;
		
		/* Do what is supposed to be done */
		switch (cmd->commandType) {
			case VoodooWirelessCommand::cmdExitThread:
				shouldExit = true;
				break;
				
			case VoodooWirelessCommand::cmdPowerOn:
				if (turnPowerOn() != kIOReturnSuccess) {
					DBG(dbgFatal, "CMD: Turn power on command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Card power turned ON\n");
					setPowerOn();
				}
				break;
				
			case VoodooWirelessCommand::cmdPowerOff:
				if (turnPowerOff() != kIOReturnSuccess) {
					DBG(dbgFatal, "CMD: Turn power off command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Card power turned OFF\n");
					setPowerOff();
				}
				break;
			
			case VoodooWirelessCommand::cmdStartScan:
				_totalResultsInCurrentScan = 0;
				if (startScan((ScanParameters*)    cmd->arg0,
					      (IEEE::ChannelList*) cmd->arg1) != kIOReturnSuccess)
				{
					DBG(dbgWarning, "CMD: Start scan command failed\n");
				} else {
					// scan has started, clear existing results in anticipation of new ones
					_scanResults->flushCollection();
					DBG(dbgInfo, "CMD: Start scan command completed\n");
					_flags |= flagScanning;
				}
				break;
			
			case VoodooWirelessCommand::cmdAbortScan:
				abortScan();
				_flags &= ~(flagScanning);
				break;
			
			case VoodooWirelessCommand::cmdAssociate: {
				AssociationParameters* assocparams = (AssociationParameters*) cmd->arg0;
				if (associate(assocparams) != kIOReturnSuccess) {
					DBG(dbgWarning, "CMD: Association command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Association command completed\n");
					_flags |= flagAssociating;
					_staState = staInit;
				}
				break;
			}
			case VoodooWirelessCommand::cmdDisassociate:
				if (disassociate() != kIOReturnSuccess) {
					DBG(dbgWarning, "CMD: Disassociation command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Disassociation command completed\n");
				}
				break;
				
			default:
				/* Ignore unknown commands */
				DBG(dbgWarning, "CMD: Unknown command type %u\n", cmd->commandType);
				break;
		};
		
		/* Destroy the command since its job is done */
		RELEASE(cmd);
	};
	
	DBG(dbgInfo, "Worker thread is exiting\n");
}


#pragma mark -
#pragma mark Network driver functions
IOReturn
MyClass::enable
( IONetworkInterface* aNetif )
{
	IOLockLock(_lock);			// Prevent re-entrancy
	
	if (_flags & flagInterfaceEnabled)	// Don't re-enable already enabled interface
		goto fail;
	if (!(_flags & flagResourcesAllocated))	// Make sure resources have been allocated already
		goto fail;
	if (!(_flags & flagPowerOn)) {		// Turn hw power on if needed
		if (turnPowerOn() != kIOReturnSuccess)
			goto fail;
		setPowerOn();
	}
	
	setLinkStatus(kIONetworkLinkValid);
	_netif->setLinkState(kIO80211NetworkLinkDown, 0 /* meaning of this param is unknown */);	// down until we associate
	getOutputQueue()->setCapacity(_hwInfo.txQueueSize);
	
	_flags |= flagInterfaceEnabled;
	IOLockUnlock(_lock);
	return kIOReturnSuccess;
	
fail:
	DBG(dbgFatal, "Could not enable the interface!\n");
	IOLockUnlock(_lock);
	return kIOReturnError;
}


IOReturn
MyClass::disable
( IONetworkInterface* aNetif )
{
	IOLockLock(_lock);			// Prevent re-entrancy
	
	if (!(_flags & flagInterfaceEnabled))	// Don't disable already disabled interface
		goto fail;
	
	setLinkDown();
	
	if (_flags & flagPowerOn) {		// Turn off if needed
		if (turnPowerOff() != kIOReturnSuccess)
			goto fail;
		setPowerOff();
	}
	
	_flags &= ~(flagInterfaceEnabled);
	IOLockUnlock(_lock);
	return kIOReturnSuccess;
	
fail:
	DBG(dbgFatal, "Could not disable the interface!\n");
	IOLockUnlock(_lock);
	return kIOReturnError;
}


IOOutputQueue* MyClass::createOutputQueue( )
{
	// Create a gated output queue with the 802.11 workloop, with size set to the HW's tx queue size
	_queue = IOGatedOutputQueue::withTarget(this, getWorkLoop(), _hwInfo.txQueueSize);
	return _queue;
}


UInt32
MyClass::outputPacket
( mbuf_t m, void* param )
{
	if (_staState != staAssociated) {
		// Send packets to endless pit!
		DBG(dbgWarning, "Tx packet while not associated. Dropping\n");
		freePacket(m);
		return kIOReturnOutputDropped;
	}
	
	if (mbuf_type(m) == MBUF_TYPE_FREE) {
		DBG(dbgWarning, "Freed packet sent for Tx! Ignoring.\n");
		return kIOReturnOutputDropped;
	}
	
	if (mbuf_len(m) <= 14) {
		DBG(dbgWarning, "Tx packet too small (len=%u). Dropping.\n", mbuf_pkthdr_len(m));
		freePacket(m);
		return kIOReturnOutputDropped;
	}
	
	/*
	 * We were sent an 802.3 ethernet frame. We'll convert this to an 802.11 wifi frame
	 * and send this to the hardware.
	 */
	IEEE::MACAddress bssid, da, sa;
	IEEE::EthernetFrameHeader* etherhdr = (IEEE::EthernetFrameHeader*) mbuf_data(m);
	
	/* Get source/dest MAC addresses and BSSID from the ethernet frame */
	bcopy(&_currentAssocData.ad_bssid,	(uint8_t*) &bssid, 6);
	bcopy(&etherhdr->da,			(uint8_t*) &da,	   6);
	bcopy(&etherhdr->sa,			(uint8_t*) &sa,    6);
	
	/* Tack on LLC/SNAP header */
	const uint8_t llc_dat[] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };
	const uint8_t llc_arp[] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8 };
	
	if (etherhdr->etherType == ETHERTYPE_ARP)
		bcopy(llc_arp, ((uint8_t*) mbuf_data(m)) + 6, 6);
	else
		bcopy(llc_dat, ((uint8_t*) mbuf_data(m)) + 6, 6);
	
	/* Remove extra 6 bytes from front.
	 * Explanation: Ethernet frame format is: [addr1][addr2][ethertype][data..]
	 *		Number of bytes:	     6      6        2
	 * So total 14 bytes. We just overwrote addr2 with the LLC/SNAP header.
	 * Now we have to remove addr1, so final format will be: [llc][ethertype][data]
	 *							   6       2		*/
	mbuf_adj(m, 6);
	
	/* Prepare the 802.11 header for a data frame */
	IEEE::TxDataFrameHeader txhdr;
	bzero(&txhdr, sizeof(txhdr));
	txhdr.hdr.type		= IEEE::WiFiFrameHeader::DataFrame;
	txhdr.hdr.subtype	= IEEE::WiFiFrameHeader::Data;
	txhdr.hdr.toDS		= 1; /* we are sending to a DS (ie. the AP) */
	
	bcopy(&bssid,	txhdr.bssid,	6);
	bcopy(&da,	txhdr.da,	6);
	bcopy(&sa,	txhdr.sa,	6);
	
	/* At this point, the mbuf has the data portion and txhdr has the 24 byte 802.11 header.
	 * Now we want to prepend the 802.11 header to the mbuf
	 */
	mbuf_t mnew = allocatePacket(mbuf_pkthdr_len(m) + sizeof(txhdr));
	if (!mnew) {
		DBG(dbgWarning, "Could not prepend 802.11 frame header during Tx. Packet dropped.\n");
		return kIOReturnOutputDropped;
	}
	
	/* Copy 802.11 header */
	mbuf_copyback(mnew, 0, sizeof(txhdr), &txhdr, MBUF_DONTWAIT);
	
	/* Now coalesce and copy the payload */
	size_t left = mbuf_pkthdr_len(m);
	size_t total = left;
	mbuf_t origm = m;
	
	while (left > 0 && m != 0) {
		mbuf_copyback(mnew, total - left + sizeof(txhdr), mbuf_len(m), mbuf_data(m), MBUF_DONTWAIT);
		left -= mbuf_len(m);
		m = mbuf_next(m);
	};
	
	freePacket(origm);
	
	/* Dump the packet */
	//DUMP_MBUF(mnew, "Tx");
	
	/* Now we have converted the mbuf to an 802.11 frame, transmit it */
	TxFrameHeader hdr;
	hdr.rate	= IEEE::rateUnspecified;
	hdr.encrypted	= false;
	
	if (_cipher && _cipherContext) { // lazy way to check if we need to encap it
		if (_cipher->encap(_cipherContext, &mnew) == false) { // some error during encap
			if (mnew) freePacket(mnew);
			return kIOReturnOutputDropped;
		}
		hdr.encrypted = true;
		IEEE::WiFiFrameHeader* whdr = (IEEE::WiFiFrameHeader*) mbuf_data(mnew);
		whdr->protectedFrame = true;
	}
	//DUMP_MBUF(mnew, "Tx WEP");
	DBG(dbgInfo, "Outputting raw 802.11 packet len=%u\n", mbuf_pkthdr_len(mnew));
	return outputFrame( hdr, mnew );
}


void
MyClass::inputFrame
( RxFrameHeader hdr, mbuf_t m )
{
	IEEE::RxDataFrameHeader*	rxhdr;
	IEEE::EthernetFrameHeader	ethhdr;
	
	rxhdr = (IEEE::RxDataFrameHeader*) mbuf_data(m);
	bcopy(&hdr, &_lastRxFrameHeader, sizeof(hdr));	// save for later use during apple80211request etc.
	
	/* Update signal level (2-point moving average) */
	_currentSignalLevel = (_currentSignalLevel + todBm(hdr.signalLevel)) / 2;
	
	if ((rxhdr->hdr.type	== IEEE::WiFiFrameHeader::DataFrame))
	{
		/*
		 * We got sent an 802.11 data frame. Convert to Ethernet II frame and pass to OS X
		 *
		 * Format of input:	[Wifi hdr][LLC hdr][Ethertype][data...]
		 *			    24        6         2
		 * Format of output:	[Ethernet hdr][ethertype][data...]
		 *			      12            2					*/
		
		/* Sanity check first (ie. for Null frames etc) */
		if (mbuf_len(m) <= (6 + 2 + sizeof(*rxhdr))) {
			// no data?
			DBG(dbgWarning, "Too small packet received len=%u. Dropped.", mbuf_len(m));
			freePacket(m);
			return;
		}
		
		/* Check if this is a multicast packet sent by us and being echoed back. If yes, discard it */
		if (rxhdr->bssid[0] & 0x01 /* multicast packet */
		    && strncmp((char*) rxhdr->sa, (char*) _hwInfo.hardwareAddress.bytes, 6) == 0 /* source is us */)
		{
			/* Discard packet */
			DBG(dbgInfo, "Discarding multicast echo packet\n");
			freePacket(m);
			return;
		}
		
		/* Copy source and dest MAC addresses */
		bcopy(rxhdr->sa, ethhdr.sa, 6);
		bcopy(rxhdr->da, ethhdr.da, 6);
		
		//DUMP_MBUF(m, "Rx WIFI");
		
		/* Decrypt if needed */
		if (_cipher && _cipherContext) {
			if (_cipher->decap(_cipherContext, &m) == false) {
				DBG(dbgWarning, "Rx wep frame decryption failed!\n");
				if (m) freePacket(m);
				return;
			}
		}
		
		//DUMP_MBUF(m, "Rx WEP");
		
		/* Overwrite the front of frame with saved SA/DA, leaving ethertype untouched */
		bcopy(&ethhdr, ((uint8_t*) mbuf_data(m)) + 24 - 6, 12);
		
		/* We don't need Wifi header anymore, so trim bytes from front */
		mbuf_adj(m, 24 - 6);
		
		/* Our job is now done. Pass it up the networking stack */
		//DUMP_MBUF(m, "Rx OSX");
		inputPacket(m);
	} else
	if ((_flags & flagScanning) &&	/* If a scan is in progress */
	    
	    (((rxhdr->hdr.type	== IEEE::WiFiFrameHeader::ManagementFrame) && 	    /* And we got a probe response */
	     (rxhdr->hdr.subtype== IEEE::WiFiFrameHeader::ProbeResponse)) ||
	    
	    ((rxhdr->hdr.type	== IEEE::WiFiFrameHeader::ManagementFrame) &&	    /* Or a beacon */
	     (rxhdr->hdr.subtype== IEEE::WiFiFrameHeader::Beacon))))
	{
		/* Then we have a scan result. Store this */
		handleScanResultFrame(hdr, m);
		
	} else {
		/*DBG(dbgInfo, "Unknown packet type received, len = %u, type %u subtype %u\n",
		    mbuf_pkthdr_len(m), rxhdr->hdr.type, rxhdr->hdr.subtype);*/
		freePacket(m);
	}
}


void
MyClass::handleScanResultFrame
( RxFrameHeader hdr, mbuf_t m )
{
	/* 
	 * We received a probe response or a beacon during a scan. Handle it!
	 *
	 * NOTE: The difference between a beacon and a probe response is minimal, typically only
	 *	 in the framecontrol bytes for which the subtype field is different. Beacons may
	 *	 also send more or less info than a probe response, in which the IEs sent are as
	 *	 requested in the probe request. Bottomlie: For our purpose, we can treat them
	 *	 exactly the same way.
	 */
	
	/* Allocate storage for the new result */
	apple80211_scan_result res;
	
	//DBG(dbgInfo, "Got scan result #%u\n", _scanResults->getCount() + 1);
	
	/* Convert and store into the allocated OSData */
	probeResponseToScanResult(hdr, m, &res);
	freePacket(m); // Because we no longer need the mbuf, all data is in res
	
	OSData* scanresult = OSData::withBytes(&res, sizeof(res));
	if (!scanresult) {
		DBG(dbgWarning, "Could not allocate OSData to store scan result\n");
		return;
	}
	
	/* Now compare with each item in the scan results array to make sure this is not a duplicate */
	OSData* s; bool found = false;
	apple80211_scan_result* sr;
	for (int i = 0; i < _scanResults->getCount(); i++) {
		
		s  = OSDynamicCast(OSData, _scanResults->getObject(i));
		sr = (apple80211_scan_result*) s->getBytesNoCopy();
		
		if (scanResultsAreSimilar(sr,
					  (apple80211_scan_result*) scanresult->getBytesNoCopy()))
		{
			found = true;
			break;
		}
	}
	
	if (found) {
		//DBG(dbgWarning, "Skipping duplicate scan result\n");
		RELEASE(scanresult);
		return;
	}
	
	_scanResults->setObject(scanresult);
	_resultsPending = _scanResults->getCount();	// at this point we've (hopefully) not yet started sending
							// results so this should be safe
	
	// Safety mechanism: if we end up with TOO many results, abort the scan
	if (++_totalResultsInCurrentScan > MAX_SCAN_RESULTS) {
		DBG(dbgWarning, "Aborting scan due to too many responses. Actual results = %u\n", _resultsPending);
		abortScan();
		report(msgScanAborted);
	}
	
	RELEASE(scanresult); // adding to array retains a reference
}


apple80211_scan_result*
MyClass::findScanResult
( apple80211_assoc_data* a )
{
	// find the scan result corresponding to the given assoc params
	if (!a) return false;
	if (_scanResults->getCount() == 0) return false;
	
	apple80211_scan_result*	sr;
	const char		allZeroes[]	= { 0, 0, 0, 0, 0, 0 };
	OSData*			oneResult;
	bool			matchBSSID	= (strncmp((char*) &a->ad_bssid, allZeroes, 6) == 0);
	
	for (int i = 0; i < _scanResults->getCount(); i++) {
		// Get next scan result from the list
		oneResult = OSDynamicCast(OSData, _scanResults->getObject(i));
		if (!oneResult) continue;
		sr = (apple80211_scan_result*) oneResult->getBytesNoCopy();
		
		// if bssid match is needed, match that first
		if (matchBSSID) {
			if (strncmp((char*) &a->ad_bssid, (char*) sr->asr_bssid, 6) == 0) {
				// bssid matched, return this result
				return sr;
			}
		}
		// for this scan result, bssid didn't match (or wasn't needed), so match ssid
		if (strncmp((char*) sr->asr_ssid,
			    (char*) a->ad_ssid,
			    min(a->ad_ssid_len, sr->asr_ssid_len)) != 0)
		{
			// ssid also didn't match, move on
			continue;
		} else {
			// ssid matched, return this result
			return sr;
		}
	}
	// if we reached here, means no results were found
	return false;
}

bool
MyClass::scanResultsAreSimilar
( const apple80211_scan_result* a, const apple80211_scan_result* b )
{
	/* This function will check for "equality" of two scan results.
	 * The definition of equality is debatable.
	 */
	
	/* First test: SSID should be same */
	if (strncmp((char*) a->asr_ssid,
		    (char*) b->asr_ssid,
		    min(a->asr_ssid_len, b->asr_ssid_len)) != 0)
		return false;
	
	/* Next, BSSID should match */
	if (strncmp((char*) a->asr_bssid,
		    (char*) b->asr_bssid, 6) != 0)
		return false;
	
	/* Check if it's the same channel */
	if (a->asr_channel.channel != b->asr_channel.channel)
		return false;
	
	/* .. with the same flags */
	if (a->asr_channel.flags != b->asr_channel.flags)
		return false;
	
	/* Check capability flags */
	if (a->asr_cap != b->asr_cap)
		return false;
	
	/* Channel, SSID, BSSID and Cap flags match. Lastly match on no. of supported rates */
	if (a->asr_nrates != b->asr_nrates)
		return false;
	
	/* At this stage, no. of supported rates are the same, so the last thing we'll do is match those */
	for (int i = 0; i < a->asr_nrates; i++)
		if (a->asr_rates[i] != b->asr_rates[i])
			return false;
	
	/* Channel, SSID, BSSID, cap flags and supported rates ALL match then it's the same goddamn thing */
	return true;
}


IOReturn
MyClass::probeResponseToScanResult
( RxFrameHeader hdr, mbuf_t m, apple80211_scan_result* ret )
{
	/*
	 * This function takes a frame received from the hardware, parses it and gets the
	 * IEEE 802.11 MAC frame from it. Then it parses that frame, and extracts relevant
	 * data out of it and stuffs the given scan result pointer with the values.
	 */
	if (!ret)
		return kIOReturnBadArgument;
	
	uint8_t* data = (uint8_t*) mbuf_data(m);
	IEEE::ProbeResponseFrameHeader* resp = (IEEE::ProbeResponseFrameHeader*) data;
	
	bzero(ret, sizeof(apple80211_scan_result));
	
	ret->version		= APPLE80211_VERSION;
	ret->asr_channel.channel= hdr.channel.number;
	ret->asr_channel.flags	=	APPLE80211_C_FLAG_10MHZ |
					APPLE80211_C_FLAG_2GHZ  |
					APPLE80211_C_FLAG_ACTIVE;
	ret->asr_beacon_int	= resp->beaconInterval;
	ret->asr_cap		= resp->capability;
	ret->asr_noise		= -90; // default for now
	ret->asr_rssi		= todBm(hdr.signalLevel);
	ret->asr_age		= 0; // XXX
	ret->asr_ie_len		= mbuf_pkthdr_len(m) - sizeof(IEEE::ProbeResponseFrameHeader);
	
	bcopy(resp->mgmt.bssid, ret->asr_bssid, 6);
	
	/* Process info elements */
	IEEE::IE* infoelem = (IEEE::IE*) (resp + 1);
	int		i;
	uint8_t*	infoelemData;
	
	/* First copy all IEs into the scan result */
	if (ret->asr_ie_len > 0) {
		ret->asr_ie_data = IOMalloc(ret->asr_ie_len);
		bcopy(infoelem, ret->asr_ie_data, ret->asr_ie_len);
	}
	
	/* Iterate over each info element, setting relevant properties in the result */
	while (((uint8_t*) infoelem) - data < mbuf_pkthdr_len(m)) { /* (while next infoelem is within frame length) */
		
		infoelemData = (uint8_t*) (infoelem + 1);
		
		switch (infoelem->id) {
			case IEEE::IE::ieSSID:
				/* Set the SSID length, zero out any existing SSID and copy the new one */
				ret->asr_ssid_len = infoelem->length;
				bzero(ret->asr_ssid, APPLE80211_MAX_SSID_LEN);
				bcopy(infoelemData, ret->asr_ssid, infoelem->length);
				break;
			case IEEE::IE::ieDSParamSet:
				/* This contains the current channel number for DSSS PHYs
				 * In this case we should set the result's channel number
				 * to whatever is sent in this info elem instead of the
				 * channel on which the frame was received (because the
				 * interference between channels can cause requests to be
				 * received even on adjacent channels) */
				ret->asr_channel.channel = *infoelemData;
				break;
			case IEEE::IE::ieSupportedRates:
			case IEEE::IE::ieExtendedSupportedRates:
				/* Each 'rate' is stored as 1 byte */
				for (i = 0; i < (infoelem->length); i++)
					ret->asr_rates[ret->asr_nrates++] = infoelemData[i];
				break;
		};
		
		infoelem = (IEEE::IE*) (((uint8_t*) infoelem) + infoelem->length + 2);
	};
	return kIOReturnSuccess;
}


int
MyClass::todBm
( int val )
{
	int ret;
	switch (_hwInfo.snrUnit) {
		case HardwareInfo::unit_dBm:
			return val;
		case HardwareInfo::unit_Percent:
			/* Map 0% to 100% to -120 dBm to -20 dBm, clipped */
			ret = (0 - (100 - val)) - 20;
			return max(-120, min(ret, -20));
		case HardwareInfo::unit_mW:
			/* This is tricky business, I choose to take the shorter route */
			/* Map 0 to 50 mW to -120 to -20 dB, clipped */
			ret = (0 - (100 - val * 20)) - 20;
			return max(-120, min(ret, -20));
		case HardwareInfo::unit_Other_Linear:
		case HardwareInfo::unit_Other_Logarithmic:
		default:
			/* We have no basis... TODO: Improve it later */
			return val;
	};
}


void
MyClass::report
( DeviceResponseMessage msg, void* arg )
{
	switch (msg) {
		case msgPowerOn:
		case msgRadioOn:
			_flags |= flagPowerOn;
			_flags &= ~(flagAssociating);
			_flags &= ~(flagScanning);
			_staState = staInit;
			setLinkDown();
			_netif->postMessage(APPLE80211_M_POWER_CHANGED);
			break;
			
		case msgPowerOff:
		case msgRadioOff:
			_flags &= ~(flagPowerOn);
			_flags &= ~(flagAssociating);
			_flags &= ~(flagScanning);
			_staState = staInit;
			setLinkDown();
			_netif->postMessage(APPLE80211_M_POWER_CHANGED);
			break;			
		
		case msgAssociationDone:
			_flags &= ~(flagAssociating);
			_staState = staAssociated;
			_netif->postMessage(APPLE80211_M_ASSOC_DONE);
			setLinkUp();
			break;
			
		case msgAssociationFailed:
			_flags &= ~(flagAssociating);
			if (arg)
				_lastReasonCode = *((IEEE::ReasonCode*) arg);
			else
				_lastReasonCode = IEEE::reasonUnspecified;
			_netif->postMessage(APPLE80211_M_ASSOC_DONE);
			break;
			
		case msgAuthenticationDone:
			if (_staState == staInit) _staState = staAuthenticated;
			break;
			
		case msgAuthenticationFailed:
			_flags &= ~(flagAssociating);
			_staState = staInit;
			if (arg)
				_lastReasonCode = *((IEEE::ReasonCode*) arg);
			else
				_lastReasonCode = IEEE::reasonUnspecified;
			_netif->postMessage(APPLE80211_M_ASSOC_DONE);
			break;
			
		case msgDisassociated:
			if (_staState == staAssociated)
				_staState = staAuthenticated;
			else
				_staState = staInit;
			if (arg)
				_lastReasonCode = *((IEEE::ReasonCode*) arg);
			else
				_lastReasonCode = IEEE::reasonUnspecified;
			setLinkDown();
			break;
			
		case msgDeauthenticated:
			_staState = staInit;
			if (arg)
				_lastReasonCode = *((IEEE::ReasonCode*) arg);
			else
				_lastReasonCode = IEEE::reasonUnspecified;
			setLinkDown();
			break;
			
		case msgScanCompleted:
		case msgScanAborted:
			_flags &= ~(flagScanning);
			_netif->postMessage(APPLE80211_M_SCAN_DONE);
			break;
			
		case msgNoiseLevelReport:
			if (arg) _currentNoiseLevel = todBm(*((int*) arg));
			break;
			
		default:
			DBG(dbgWarning, "Unhandled message received from subclass: %u\n", msg);
			break;
	};
}




//*********************************************************************************************************************
#pragma mark -
#pragma mark Quick implementation of tiny functions
//*********************************************************************************************************************
const OSString*	MyClass::newVendorString	( ) const	{ return _hwInfo.manufacturer; }
const OSString*	MyClass::newModelString		( ) const	{ return _hwInfo.model; }
const OSString*	MyClass::newRevisionString	( ) const	{ return _hwInfo.hardwareRevision; }

IOReturn
MyClass::getHardwareAddress
( IOEthernetAddress* addr )
{
	bcopy(_hwInfo.hardwareAddress.bytes, addr->bytes, 6);
	return kIOReturnSuccess;
}

IOReturn
MyClass::getHardwareAddressForInterface
( IO80211Interface* netif, IOEthernetAddress* addr )
{
	bcopy(_hwInfo.hardwareAddress.bytes, addr->bytes, 6);
	return kIOReturnSuccess;
}

IOReturn
MyClass::getMaxPacketSize
( UInt32 *maxSize ) const
{
	*maxSize = _hwInfo.maxPacketSize;
	return kIOReturnSuccess;
}

void
MyClass::setPowerOn( )
{
	_flags &= ~(flagScanning | flagAssociating);
	_flags |= flagPowerOn;
	_staState = staInit;
	setLinkDown(); // because we just turned on
	_netif->postMessage(APPLE80211_M_POWER_CHANGED);
}

void
MyClass::setPowerOff( )
{
	_flags &= ~(flagPowerOn | flagScanning | flagAssociating);
	_staState = staInit;
	setLinkDown();
	_netif->postMessage(APPLE80211_M_POWER_CHANGED);
}

void
MyClass::setLinkUp( )
{
	/*
	 * Setup a cipher if needed before marking link as up
	 */
	
	if (_currentAssocData.ad_key.key_cipher_type == APPLE80211_CIPHER_WEP_40 ||
	    _currentAssocData.ad_key.key_cipher_type == APPLE80211_CIPHER_WEP_104)
	{
		if (_cipher) { // only if we actually HAVE a wep cipher
			
			if (_cipherContext)
				_cipher->freeContext(_cipherContext); // free any old context
			_cipherContext	= _cipher->initContext(); // create fresh context for this connection
			
			_cipherKey.keyLength	= _currentAssocData.ad_key.key_len;
			_cipherKey.keyIndex	= _currentAssocData.ad_key.key_index;
			bcopy(_currentAssocData.ad_key.key, _cipherKey.key, _cipherKey.keyLength);
			
			_cipher->setKey(_cipherContext, &_cipherKey);
			DBG(dbgInfo, "WEP software cipher initialized for this connection\n");
		} else
			DBG(dbgWarning, "WEP connection is up, but we have no SW cipher!\n")
	}
	
	_netif->setLinkState(kIO80211NetworkLinkUp, 0);
	getOutputQueue()->start();
}

void
MyClass::setLinkDown( )
{
	_netif->setLinkState(kIO80211NetworkLinkDown, 0);
	getOutputQueue()->stop();
	getOutputQueue()->flush();
	if (_cipher) {
		if (_cipherContext)
			_cipher->freeContext(_cipherContext);
		_cipherContext = 0;
	}
}

//*********************************************************************************************************************
// Following functions are dummy implementations but they must succeed for the network driver to work
#pragma mark -
#pragma mark Dummy functions
//*********************************************************************************************************************
IOReturn	MyClass::setPromiscuousMode	( IOEnetPromiscuousMode mode )		{ return kIOReturnSuccess; }
IOReturn	MyClass::setMulticastMode	( IOEnetMulticastMode mode )		{ return kIOReturnSuccess; }
IOReturn	MyClass::setMulticastList	( IOEthernetAddress* addr, UInt32 len )	{ return kIOReturnSuccess; }
SInt32		MyClass::monitorModeSetEnabled	( IO80211Interface * interface,
						  bool enabled, UInt32 dlt )		{ return kIOReturnSuccess; }

//*********************************************************************************************************************
// Hardware specific functions to be implemented by subclasses. Putting dummy implementations here
#pragma mark -
#pragma mark To be subclassed
//*********************************************************************************************************************
IOReturn	MyClass::allocateResources	( IOService* provider )			{ return kIOReturnUnsupported; }
void		MyClass::freeResources		( IOService* provider )			{ return; }
IOReturn	MyClass::turnPowerOn		( )					{ return kIOReturnUnsupported; }
IOReturn	MyClass::turnPowerOff		( )					{ return kIOReturnUnsupported; }
IOReturn	MyClass::startScan		( const ScanParameters* params,
						  const IEEE::ChannelList* channels )	{ return kIOReturnUnsupported; }
void		MyClass::abortScan		( )					{ return; }
IOReturn	MyClass::associate		( const AssociationParameters* params )	{ return kIOReturnUnsupported; }
IOReturn	MyClass::disassociate		( )					{ return kIOReturnUnsupported; }
void		MyClass::getHardwareInfo	( HardwareInfo* info )			{ return; }
IOReturn	MyClass::getConfiguration	( HardwareConfigType type, void* param ){ return kIOReturnUnsupported; }
IOReturn	MyClass::setConfiguration	( HardwareConfigType type, void* param ){ return kIOReturnUnsupported; }
IOReturn	MyClass::outputFrame		( TxFrameHeader hdr, mbuf_t data )	{ return kIOReturnUnsupported; }

OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 0);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 1);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 2);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 3);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 4);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 5);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 6);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 7);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 8);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 9);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 10);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 11);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 12);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 13);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 14);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 15);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 16);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 17);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 18);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 19);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 20);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 21);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 22);
OSMetaClassDefineReservedUnused(VoodooWirelessDevice, 23);
