/*
 *  VoodooWirelessDevice_Types.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 16/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSDEVICE_TYPES_H
#define _H_VOODOOWIRELESSDEVICE_TYPES_H

#include <libkern/c++/OSSymbol.h>
#include <libkern/c++/OSString.h>
#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211.h"

namespace org_voodoo_wireless {
	
	struct ScanParameters {
		enum ScanType {	scanTypeActive, scanTypePassive, scanTypeBackground };
		ScanType		scanType;	// Type of scan (active/passive..)
		IEEE::PHYModes		scanPhyMode;	// 11a,b,g or n on which to scan
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
		IEList*			extraIEs;	// extra information elements sent in the probe response
	};
	
	struct RxFrameHeader {
		/* information about an incoming frame */
		IEEE::Channel		channel;
		IEEE::DataRate		rate;
		int			signalLevel;	// signal strength preferably in dBm
		bool			wepDecrypted;	// whether HW has already decrypted this frame
	};
	
	struct TxFrameHeader {
		IEEE::DataRate		rate;
	};
	
	struct HardwareCapabilities {
		/* Which features does the hardware support */
		bool	WEP		:1;	// Should always be true because software WEP is supported by superclass
		bool	TKIP		:1;
		bool	AES		:1;
		bool	AES_CCM		:1;
		bool	TKIP_MIC	:1;
		bool	WPA1		:1;
		bool	WPA2		:1;
		bool	CKIP		:1;
		bool	TSN		:1;	// WPA with WEP group key
		
		bool	AdHocMode	:1;
		bool	HostAPMode	:1;
		bool	MonitorMode	:1;
		
		bool	PowerManagement	:1;	// active 802.11 power management, not IOKit power management
		bool	TxPowerManagement:1;	// transmit power can be set
		bool	WakeOneWireless	:1;
		
		bool	ShortSlot	:1;
		bool	ShortPreamble	:1;
		bool	FrameBursting	:1;
		bool	WMEQoS		:1;
		bool	ShortGuardInterval20MHz	:1;
		bool	ShortGuardInterval40MHz	:1;
	};
	
	struct HardwareInfo {
		/* Note: strings should not have been allocated already, they will be allocated
			 by the driver itself. Ownership is then passed to the client who must
			 release the strings. In other words, this struct should be zero filled
			 before being passed to provider. */
		OSString*		manufacturer;
		OSString*		model;
		OSString*		hardwareRevision;
		OSString*		driverVersion;
		OSString*		firmwareVersion;
		IEEE::PHYModes		supportedModes;		// OR'd bits if it's multi-mode PHY
		IEEE::ChannelList	supportedChannels;	// independent of locale
		IEEE::RateSet		supportedRates;
		HardwareCapabilities	capabilities;
	};
	
	enum DeviceResponseMessage {
		msgNull	= iokit_vendor_specific_msg(1),	// XXX: not used
		
		msgPowerChanged,		// power was preemptively turned on/off (ie. not initiated by client)
		// arg=bool turnedOn
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
		
		msgNoiseLevelReport,		// reporting noise level, arg=int noiseLevel
		msgLinkQualityReport,		// reporting link quality, arg=int qualityLevel
		msgBeaconMissed,		// reporting missed beacon, arg=uint32_t howManyMissed
		
		msgMaxMessageNumber		// XXX: used to check if msg num was out of bound
	};
};

#endif
