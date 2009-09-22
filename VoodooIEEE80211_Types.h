/*
 *  VoodooIEEE80211_Types.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 16/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */


#ifndef _H_VOODOOIEEE80211_TYPES_H
#define _H_VOODOOIEEE80211_TYPES_H

#include "VoodooWirelessFamily.h"

namespace org_voodoo_wireless {
namespace IEEE {
	struct MACAddress {
		/* Defining this again here because families should not have to use another
		 family's headers, and IOEthernetAddress is defined in IOEthernetFamily */
		uint8_t bytes[6];
	};
	
	struct WEPKey {
		uint8_t		index;		// 0 to 3
		size_t		length;		// 40 or 104 bits (5 or 13 bytes)
		uint8_t		key[13];
	};
	
	enum PHYModes {
		phyModeAuto = 1,	// auto-select
		dot11A	= 2,		// 5GHz OFDM
		dot11B	= 4,		// 2.4GHz CCK
		dot11G	= 8,		// 2.4GHz OFDM
		dot11N	= 0x10,		// 2.4GHz or 5GHz MIMO
	};
	
	const size_t MAX_CHANNELS = 64;
	const size_t MAX_RATES = 32;
	
	struct Channel {
		uint8_t			number;		// Channel number
		uint16_t		flags;		// Channel type flags
		enum Flags {
			// These values correspond to apple80211's channel flags
			supportsActiveScanning	= 0x80,
			band2GHz		= 0x8,
			band5GHz		= 0x10,
			width10MHz		= 0x1,
			width20MHz		= 0x2,
			width40MHz		= 0x4,
			requiresDFS		= 0x100, // dynamic frequency selection for 11a
			supportsHostAPMode	= 0x40,
			supportsAdHocMode	= 0x20,
			extensionChannelIsAbove	= 0x200, // in 11n mode, if ext. ch is above this ch. (otherwise below)
			
			default11BGChannelFlags	= (supportsActiveScanning | band2GHz | width10MHz),
			default11AChannelFlags	= (supportsActiveScanning | band5GHz | width10MHz)
		};
	};
	
	struct ChannelList {
		size_t			numItems;
		Channel			channel[MAX_CHANNELS];
	};
	
	enum DataRate {
		rateIsBasic	= 128,	// basic rates should be OR'd with this value (ie. bit 7 = 1)
		/* Rates are just uint32_t, in 0.5 Mbps units */
		rateUnspecified	= 0,	// unknown speed
		rate1Mbps	= 2,	// 1 Mbps CCK
		rate2Mbps	= 4,	// 2 Mbps CCK
		rate5Mbps	= 10,	// 5.5 Mbps CCK
		rate6Mbps	= 12,	// 6 Mbps OFDM
		rate9Mbps	= 18,	// 9 Mbps OFDM
		rate11Mbps	= 22,	// 11 Mbps CCK
		rate12Mbps	= 24,	// 12 Mbps OFDM
		rate18Mbps	= 36,	// 18 Mbps OFDM
		rate24Mbps	= 48,	// 24 Mbps OFDM
		rate36Mbps	= 72,	// 36 Mbps OFDM
		rate48Mbps	= 96,	// 48 Mbps OFDM
		rate54Mbps	= 108,	// 54 Mbps OFDM
		/* 11n MIMO rates to be added later */
	};
	
	struct RateSet {
		size_t			numItems;
		DataRate		rate[MAX_RATES];
	};
	
	enum ReasonCode {
		// § 7.3.1.7 Table 7-22
		reasonUnspecified		= 1,
		reasonPreviousAuthExpired	= 2,
		reasonDeauthBecauseSTALeft	= 3,
		reasonDisassocDueToInactivity	= 4,
		reasonAPFull			= 5,
		reasonClass2FrameRxWithoutAuth	= 6,
		reasonClass3FrameRxWithoutAssoc	= 7,
		reasonDisassocBecauseSTALeft	= 8,
		reasonNotAuthorized		= 9,
		reasonPowerCapsUnacceptable	= 10,
		reasonSupportedChannelsUnacceptable = 11,
		reasonInvalidIE			= 13, /* 12 is reserved */
		reasonMICFailure		= 14,
		reason4WayHandshakeTimeout	= 15,
		reasonGroupKeyHandshakeTimeout	= 16,
		reasonIEMismatch		= 17,
		reasonInvalidGroupCipher	= 18,
		reasonInvalidPairwiseCipher	= 19,
		reasonInvalidAKMP		= 20,
		reasonUnsupportedRSNIE		= 21,
		reasonInvalidRSNIECaps		= 22,
		reason8021XAuthFailed		= 23,
		reasonCipherSuiteRejected	= 24,
		reasonQoS			= 32, /* 25-31 reserved */
		reasonQoSBandwidthUnavailable	= 33,
		reasonTooManyACKs		= 34,
		reasonTXOPsOutsideLimits	= 35,
		reasonPeerSTALeaving		= 36,
		reasonPeerSTAMechanismRejected	= 37,
		reasonPeerSTAMechanismNeedsSetup= 38,
		reasonPeerSTATimeout		= 39,
		reasonPeerSTACipherUnsupported	= 45, /* 40-44 reserved */
		reasonPrivateUnspecified	= 0xffff /* our own unspecified failure code */
	};
	
	struct IE {
		enum ID {
			/* § 7.3.2 Table 7-26 */
			ieSSID			= 0,	ieSupportedRates	= 1,
			ieFHParamSet		= 2,	ieDSParamSet		= 3,
			ieCFParamSet		= 4,	ieTIM			= 5,
			ieIBSSParamSet		= 6,	ieCountry		= 7,
			ieHoppingPatternParams	= 8,	ieHoppingPatternTable	= 9,
			ieRequest		= 10,	ieBSSLoad		= 11,
			ieEDCAParamSet		= 12,	ieTSPEC			= 13,
			ieTCLAS			= 14,	ieSchedule		= 15,
			ieChallengeText		= 16,	/* 17-31 reserved */
			iePowerConstraint	= 32,	iePowerCapability	= 33,
			ieTPCRequest		= 34,	ieTPCReport		= 35,
			ieSupportedChannels	= 36,	ieChannelSwitchAnnounce	= 37,
			ieMeasurementRequest	= 38,	ieMeasurementReport	= 39,
			ieQuiet			= 40,	ieIBSSDFS		= 41,
			ieERPInformation	= 42,	ieTSDelay		= 43,
			ieTCLASProcessing	= 44,	/* 45 reserved */
			ieQoSCapability		= 46,	/* 47 reserved */
			ieRSN			= 48,	/* 49 reserved */
			ieExtendedSupportedRates= 50,	/* 51-125 reserved */
			/* 126 reserved */		ieExtendedCapabilities	= 127,
			/* 128-220 reserved */		ieVendorSpecific	= 221,
			/* 222-255 reserved */
		};
		uint8_t		id;		// type codes specified in enum ID
		uint8_t		length;		// length in bytes of data that follows
		// variable length data follows...
	} __packed;
	
	union Capability {
		struct {
			/* § 7.3.1.4 */
			bool	ESS		:1;
			bool	IBSS		:1;	// indicates Ad-hoc mode
			bool	CFPollable	:1;
			bool	CFPollRequest	:1;
			bool	Privacy		:1;	// indicates WEP on/off
			bool	ShortPreamble	:1;
			bool	PBCC		:1;
			bool	ChannelAgility	:1;
			bool	SpectrumMgmt	:1;
			bool	QoS		:1;
			bool	ShortSlotTime	:1;
			bool	APSD		:1;
			bool	Reserved	:1;
			bool	DSSSOFDM	:1;	// indicates 11g mode on/off
			bool	DelayedBlockAck	:1;
			bool	ImmediateBlockAck:1;
		} bits __packed;
		uint16_t	value;
	} __packed;
	
	
	/* Following is the structure of a MAC header present in ALL frames. The remaining
	 * contents of the frame depend on the type/subtype etc. § 7.2 onwards
	 */	
	struct WiFiFrameHeader
	{
		enum FrameType {
			ManagementFrame	= 0,
			ControlFrame	= 1,
			DataFrame	= 2,
			ReservedFrame	= 3
		};
		
		enum FrameSubtype {
			/* Subtype for Management frames: */
			AssocRequest	= 0,	AssocResponse	= 1,
			ReassocRequest	= 2,	ReassocResponse	= 3,
			ProbeRequest	= 4,	ProbeResponse	= 5,
			/* 6-7 are reserved */
			Beacon		= 8,	ATIM		= 9,
			Disassoc	= 10,	Authentication	= 11,
			DeAuthentication= 12,	Action		= 13,
			/* 14-15 are reserved */
			
			/* Subtypes for Control frames: */
			/* 0-7 are reserved */
			BlockAckReq	= 8,	BlockAck	= 9,
			PSPoll		= 10,	RTS		= 11,
			CTS		= 12,	ACK		= 13,
			CFEnd		= 14,	CFEndPoll	= 15,
			
			/* Subtypes for Data frames: */
			Data		= 0,	DataCFAck	= 1,
			DataCFPoll	= 2,	DataCFAckPoll	= 3,
			Null		= 4,	CFAck		= 5,
			CFPoll		= 6,	CFAckPoll	= 7,
			QoSData		= 8,	QoSDataCFAck	= 9,
			QoSDataCFPoll	= 10,	QoSDataCFAckPoll = 11,
			QoSNull		= 12,	/* 13 is reserved */
			QoSCFPoll	= 14,	QoSCFAckCFPoll	= 15
		};
		
		uint8_t		protocolVersion	:2;
		FrameType	type		:2;
		FrameSubtype	subtype		:4;
		bool		toDS		:1;
		bool		fromDS		:1;
		bool		moreFrag	:1;
		bool		retry		:1;
		bool		powerSaveMode	:1;	// Called PwrMgt in spec
		bool		moreData	:1;
		bool		protectedFrame	:1;
		bool		order		:1;
		
		uint16_t	durationID	:16;
	} __packed;
	
	struct SequenceControl {
		uint8_t		fragmentNumber	:4;
		uint16_t	sequenceNumber	:12;
	} __packed;
	
	struct ManagementFrameHeader
	{
		WiFiFrameHeader		hdr;
		uint8_t			da[6];
		uint8_t			sa[6];
		uint8_t			bssid[6];
		SequenceControl		sequenceControl;
	} __packed;
	
	struct ProbeResponseFrameHeader {
		ManagementFrameHeader	mgmt;
		uint64_t		timestamp;
		uint16_t		beaconInterval;
		uint16_t		capability;
		/* Then follows a variable number of information elements */
	} __packed;
	
	struct TxDataFrameHeader {
		WiFiFrameHeader		hdr;
		uint8_t			bssid[6];
		uint8_t			sa[6]; // source MAC addr
		uint8_t			da[6]; // dest MAC addr
		uint16_t		seq;
		// data follows...
	} __packed;
	
	struct RxDataFrameHeader {
		WiFiFrameHeader		hdr;
		uint8_t			da[6];
		uint8_t			bssid[6];
		uint8_t			sa[6];
		uint16_t		seq;
		// data follows...
	} __packed;
	
	struct TxQoSDataFrameHeader {
		WiFiFrameHeader		hdr;
		uint8_t			bssid[6];
		uint8_t			sa[6]; // source MAC addr
		uint8_t			da[6]; // dest MAC addr
		uint16_t		seq;
		uint16_t		qos;
		// data follows...
	} __packed;
	
	struct EthernetFrameHeader {
		uint8_t			da[6];
		uint8_t			sa[6];
		uint16_t		etherType;
		// data follows...
	} __packed;
}
}

#endif
