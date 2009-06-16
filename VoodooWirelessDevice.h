/*
 *  VoodooWirelessDevice.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 12/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSDEVICE_H
#define _H_VOODOOWIRELESSDEVICE_H

#include <IOKit/IOService.h>
#include <IOKit/IOMessage.h>
#include <IOKit/network/IOEthernetController.h>
#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211.h"

namespace org_voodoo_wireless {
	
	struct ScanParameters {
		enum ScanType {	scanTypeActive, scanTypePassive, scanTypeBackground };
		ScanType		scanType;	// Type of scan (active/passive..)
		IEEE::PHYMode		scanPhyMode;	// 11a,b,g or n on which to scan
		IEEE::MACAddress	bssid;		// BSSID to which scan is directed
		OSSymbol*		ssid;		// SSID (network name) to which scan is directed
		uint32_t		dwellTime;	// Time to stay on each channel (ms)
		uint32_t		restTime;	// Time to wait between channels (ms)
	};
	
	struct ScanResult {
		IEEE::Channel		channel;	// channel on which this AP is operating
		IEEE::Capability	capability;	// AP capability flags
		IEEE::MACAddress	bssid;		// BSSID of access point
		OSSymbol*		ssid;		// Network name
		int			noiseLevel;	// background noise in dB
		int			signalLevel;	// signal strength in dB (RSSI)
		IEEE::RateSet		supportedRates;	// rates that the AP supports
		uint32_t		beaconInterval;	// in ms
		uint32_t		age;		// how old is this result (in ms)
	};
	
	enum DeviceResponseMessages {
		msgNull	= iokit_vendor_specific_msg(1),	// XXX: not used
		msgPowerChanged,		// power was preemptively turned on/off (ie. not initiated by client)
		msgScanAborted,			// scan was aborted (by HW, not as response to client request)
		msgScanCompleted,		// scanning all specified chanels is completed
		msgChannelScanned,		// scanning a specific channel is completed (arg=Channel*)
		msgAuthenticationFailed,	// authentication step failed
		msgAuthenticationDone,		// authentication step was done
		msgAssociationFailed,		// association with AP failed, arg=IEEE::ReasonCode
		msgAssociationDone,		// association was finished successfully
		msgDeassociationFailed,		// deassoc request failed, arg=IEEE::ReasonCode
		msgDeassociationDone,		// deassociated from AP, arg=IEEE::ReasonCode
		msgDeauthenticated,		// deauthenticated from AP, arg=IEEE::ReasonCode
		msgMaxMessageNumber		// XXX: used to check if msg num was out of bound
	};
};

using namespace org_voodoo_wireless;

class VoodooWirelessDevice
{
public:

	/* Functions to init / shutdown the HW */
	virtual bool		allocateResources	( ) = 0;
	virtual void		freeResources		( ) = 0;
	virtual bool		turnPowerOn		( ) = 0;
	virtual bool		turnPowerOff		( ) = 0;
	
	/* Functions for establishing connections etc. */
	virtual bool		startScan		(const ScanParameters* params,
							 IEEE::ChannelList* channels) = 0;
	
	virtual bool		startChannelScan	(const ScanParameters* params,
							 const Channel* channel) = 0;
	
	virtual bool		abortScan		( ) = 0;
	
};

#endif//_H_VOODOOWIRELESSDEVICE_H