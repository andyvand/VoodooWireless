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
		int			noiseLevel;	// background noise
		int			signalLevel;	// signal strength
		IEEE::RateSet		supportedRates;	// rates that the AP supports
		uint32_t		beaconInterval;	// in ms
		uint32_t		age;		// how old is this result (in ms)
		IEList*			extraIEs;	// extra information elements sent in the probe response
	};
	
	struct AssociationParameters {
		OSSymbol*		ssid;
		IEEE::MACAddress	bssid;
		enum APMode { apModeAny, apModeAdHoc, apModeInfrastructure };
		APMode			connectionMode;
		enum AuthType {
			/* LSB signifies lower auth mode (to be OR'd with upper auth mode if needed) */
			authTypeNone	= 0,		// Open authentication
			authTypeShared	= 1,		// WEP key shared authentication
			/* Upper auth modes (even number only as LSB is taken) */
			authTypeWPA	= 2,
			authTypeWPAPSK	= 4,
			authTypeWPA2	= 6,
			authTypeWPA2PSK	= 8,
			authtypeLEAP	= 10,
			authType8021X	= 12,
			authTypeWPS	= 14
		};
		AuthType		authType;
		IEEE::WEPKey		wepKey;		// if key is zero length, then no WEP
		IEList*			extraIEs;	// info elements used with RSN (WPA etc.)
		bool			closedNetwork;	// indicates assoc request is for directed scanned network
	};
	
	struct RxFrameHeader {
		/* information about an incoming frame */
		IEEE::Channel		channel;
		IEEE::DataRate		rate;
		int			signalLevel;	// signal strength
		bool			wepDecrypted;	// whether HW has already decrypted this frame
	};
	
	struct TxFrameHeader {
		IEEE::DataRate		rate;		// desired Tx rate (can be ignored by HW)
		IEEE::WEPKey			wepKey;
	};
	
	struct HardwareCapabilities {
		/* Which features does the hardware support */
		bool	WEP		:1;	// Usually true because software WEP is supported by superclass
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
		
		bool	hardwareRoaming	:1;	// hardware can migrate to different APs on its own
	};
	
	enum PowerSavingModes {
		powerSaveNone		= 1,		// always on
		powerSaveAlwaysOn	= 1,
		powerSaveCAM		= 1,		// just a different names for always on
		powerSaveNormal		= 2,		// middle-level power saving
		powerSaveMaximum	= 4		// maximum power savings
	};
	
	enum HardwareConfigType {
		/* Which kind of config to get/set, when get/setConfig is called. Any of this can be ignored */
		configTxPower,			// param = int txPower
		configRTSThreshold,		// param = uint32_t threshInBytes
		configFragmentationThreshold,	// param =     "          "
		configCurrentTxRate,		// param = IEEE::DataRate
		configRateSet,			// param = IEEE::RateSet [working rates, not HW supported rates]
		configInterferenceMitigation,	// param = bool turnOn [HW dependent, usually bluetooth interference]
		config11GProtection		// param = bool turnOn [used in mixed 11bg networks]
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
		IEEE::RateSet		supportedRates;		// that hardware supports, not what it's using now
		unsigned int		maxTxPower;		// in dBm, independent of locale
		enum SNRUnit { unit_dBm, unit_Percent, unit_mW, unit_Linear, unit_Logarithmic };
		SNRUnit			snrUnit;		// which units are noise/signal levels reported in
		PowerSavingModes	powerSavingModes;	// which modes does hardware support
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
