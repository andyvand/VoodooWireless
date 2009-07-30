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

#define MyClass		VoodooWirelessDevice
#define super		IO80211Controller

enum {
	// Flags for _flags member variable
	flagResourcesAllocated	= 1,
	flagPowerOn		= 2,
	flagInterfaceEnabled	= 4,
	flagScanning		= 8,
	flagAssociating		= 16
};

enum {
	dbgFatal	= 0x1,
	dbgWarning	= 0x2,
	dbgInfo		= 0x4
};

enum {
	staInit,
	staAuthenticated,
	staAssociated
};

const int org_voodoo_wireless_debug = dbgFatal;


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
	
	/* Allocate a lock for ::enable() and ::disable() */
	_lock = IOLockAlloc();
	if (_lock == 0)
		return false;
	
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
	
	/* Retain a reference to superclass's workloop */
	_workloop = OSDynamicCast(IO80211WorkLoop, getWorkLoop());
	_workloop->retain();
	
	/* Create the command pool for queueing HW subroutines */
	_commandPool = IOCommandPool::withWorkLoop(_workloop);
	
	/* Now do HW specific initialization */
	if (allocateResources(provider) != kIOReturnSuccess) {
		DBG(dbgFatal, "Could not allocate hardware resources!\n");
		return false;
	} else {
		_flags |= flagResourcesAllocated;
	}
	
	/* HW resources are allocated, we can attach the interface now */
	if (!attachInterface((IONetworkInterface**) &_netif, /* attach to DLIL = */ true)) {
		DBG(dbgFatal, "Could not attach wireless interface!\n");
		return false;
	}
	
	/* Attach to bpf for tcpdump of raw 802.11 packets */
	_netif->bpfAttach(/* DLT	 = */ 105,
			  /* Header size = */ 30);
	
	/* And finally register this service */
	registerService();
	
	return true;
}


void
MyClass::stop
( IOService* provider )
{
	freeResources(provider);
	_flags &= ~(flagResourcesAllocated);
	
	if (_lock)
		IOLockFree(_lock);
	
	RELEASE(_hwInfo.manufacturer);
	RELEASE(_hwInfo.model);
	RELEASE(_hwInfo.hardwareRevision);
	RELEASE(_hwInfo.driverVersion);
	RELEASE(_hwInfo.firmwareVersion);
	RELEASE(_scanResults);
	RELEASE(_queue);
	RELEASE(_netif);
	RELEASE(_medium);
	RELEASE(_commandPool);
	RELEASE(_workloop);
	
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
	return kIOReturnUnsupported;
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
					_flags |= flagPowerOn;
					_netif->postMessage(APPLE80211_M_POWER_CHANGED);
				}
				break;
				
			case VoodooWirelessCommand::cmdPowerOff:
				if (turnPowerOff() != kIOReturnSuccess) {
					DBG(dbgFatal, "CMD: Turn power off command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Card power turned OFF\n");
					_flags &= ~(flagPowerOn);
					_netif->postMessage(APPLE80211_M_POWER_CHANGED);
				}
				break;
			
			case VoodooWirelessCommand::cmdStartScan:
				if (startScan((ScanParameters*)    cmd->arg0,
					      (IEEE::ChannelList*) cmd->arg1) != kIOReturnSuccess)
				{
					DBG(dbgWarning, "CMD: Start scan command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Start scan command completed\n");
					_flags |= flagScanning;
				}
				break;
				
			case VoodooWirelessCommand::cmdAbortScan:
				abortScan();
				_flags &= ~(flagScanning);
				break;
			
			case VoodooWirelessCommand::cmdAssociate:
				AssociationParameters* assocparams = (AssociationParameters*) cmd->arg0;
				if (associate(assocparams) != kIOReturnSuccess) {
					DBG(dbgWarning, "CMD: Association command failed\n");
				} else {
					DBG(dbgInfo, "CMD: Association command completed\n");
					bcopy(&assocparams->bssid, &_currentBSSID, 6);
					_currentWEPKey = assocparams->wepKey;
					_flags |= flagAssociating;
					_staState = staInit;
				}
				break;
				
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
		_flags |= flagPowerOn;
		_netif->postMessage(APPLE80211_M_POWER_CHANGED);
	}
	
	_netif->setLinkState(kIO80211NetworkLinkDown);	// down until we associate
	_queue->setCapacity(_hwInfo.txQueueSize);
	
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
	
	_netif->setLinkState(kIO80211NetworkLinkDown);
	_queue->setCapacity(0);
	_queue->stop();
	_queue->flush();
	
	if (_flags & flagPowerOn) {		// Turn off if needed
		if (turnPowerOff() != kIOReturnSuccess)
			goto fail;
		_flags &= ~(flagPowerOn);
		_netif->postMessage(APPLE80211_M_POWER_CHANGED);
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
	
	if (mbuf_pkthdr_len(m) <= 14) {
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
	bcopy(&_currentBSSID,	(uint8_t*) &bssid, 6);
	bcopy(&etherhdr->da,	(uint8_t*) &da,	   6);
	bcopy(&etherhdr->sa,	(uint8_t*) &sa,    6);
	
	/* Tack on LLC/SNAP header */
	const uint8_t llc_dat[] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0x00 };
	const uint8_t llc_arp[] = { 0xaa, 0xaa, 0x03, 0x00, 0x00, 0xf8 };
	
	if (etherhdr->etherType == ETHERTYPE_ARP)
		mbuf_copyback(m, 6, 6, llc_arp, MBUF_DONTWAIT);
	else
		mbuf_copyback(m, 6, 6, llc_dat, MBUF_DONTWAIT);			
	
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
	mbuf_prepend(&m, sizeof(txhdr), MBUF_DONTWAIT);
	if (!m) {
		DBG(dbgWarning, "Could not prepend 802.11 frame header during Tx. Packet dropped.\n");
		return kIOReturnOutputDropped;
	}
	mbuf_copyback(m, 0, sizeof(txhdr), &txhdr, MBUF_DONTWAIT);
	
	/* Now we have converted the mbuf to an 802.11 frame, transmit it */
	TxFrameHeader hdr;
	hdr.rate	= IEEE::rateUnspecified;
	hdr.encrypted	= false;
	hdr.wepKey	= _currentWEPKey;
	return outputFrame( hdr, m );
}



void
MyClass::inputFrame
( RxFrameHeader hdr, mbuf_t m )
{
	IEEE::RxDataFrameHeader*	rxhdr;
	IEEE::EthernetFrameHeader	ethhdr;
	
	rxhdr = (IEEE::RxDataFrameHeader*) mbuf_data(m);
	
	if (rxhdr->hdr.type	== IEEE::WiFiFrameHeader::DataFrame &&
	    rxhdr->hdr.subtype	== IEEE::WiFiFrameHeader::Data)
	{
		/*
		 * We got sent an 802.11 frame. Convert to Ethernet II frame and pass to OS X
		 *
		 * Format of input:	[Wifi hdr][LLC hdr][Ethertype][data...]
		 *			    24        6         2
		 * Format of output:	[Ethernet hdr][ethertype][data...]
		 *			      12            2					*/
		
		/* Copy source and dest MAC addresses */
		bcopy(rxhdr->sa, ethhdr.sa, 6);
		bcopy(rxhdr->da, ethhdr.da, 6);
		
		/* We don't need Wifi header anymore, so trim bytes from front so that we are
		 * left with 14 bytes before the 'data' part starts. */
		mbuf_adj(m, 24 - 6);
		
		/* Now overwrite the front of frame with saved SA/DA, leaving ethertype untouched */
		mbuf_copyback(m, 0, 12, &ethhdr, MBUF_DONTWAIT);
		
		/* Our job is now done. Pass it up the networking stack */
		inputPacket(m);
	} else {
		DBG(dbgWarning, "Unhandled frame type %u subtype %u received. Dropped.\n",
		    rxhdr->hdr.type, rxhdr->hdr.subtype);
		freePacket(m);
	}
}



void
MyClass::report
( DeviceResponseMessage msg, void* arg )
{
	switch (msg) {
		case msgPowerOn:
		case msgRadioOn:
			_flags |= flagPowerOn;
			_netif->postMessage(APPLE80211_M_POWER_CHANGED);
			break;
			
		case msgPowerOff:
		case msgRadioOff:
			_flags &= ~(flagPowerOn);
			_netif->postMessage(APPLE80211_M_POWER_CHANGED);
			break;			
		
		case msgAssociationDone:
			_flags &= ~(flagAssociating);
			_staState = staAssociated;
			_netif->postMessage(APPLE80211_M_ASSOC_DONE);
			_netif->setLinkState(kIO80211NetworkLinkUp);
			_queue->start();
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
			_netif->setLinkState(kIO80211NetworkLinkDown);
			_queue->stop();
			_queue->flush();
			break;
			
		case msgDeauthenticated:
			_staState = staInit;
			if (arg)
				_lastReasonCode = *((IEEE::ReasonCode*) arg);
			else
				_lastReasonCode = IEEE::reasonUnspecified;
			_netif->setLinkState(kIO80211NetworkLinkDown);
			_queue->stop();
			_queue->flush();
			break;
			
		case msgScanAborted:
			_flags &= ~(flagScanning);
			break;
			
		case msgScanCompleted:
			_flags &= ~(flagScanning);
			_netif->postMessage(APPLE80211_M_SCAN_DONE);
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
MyClass::getMaxPacketSize
( UInt32 *maxSize ) const
{
	*maxSize = _hwInfo.maxPacketSize;
	return kIOReturnSuccess;
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
