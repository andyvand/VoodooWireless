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
		uint8_t		index;		// 1 to 4
		OSString*	key;		// 40 or 104 bits (5 or 13 bytes)
	};
	
	enum PHYModes {
		dot11A	= 1,		// 5GHz OFDM
		dot11B	= 2,		// 2.4GHz CCK
		dot11G	= 4,		// 2.4GHz OFDM
		dot11N	= 8,		// 2.4GHz or 5GHz MIMO
	};
	
	const size_t MAX_CHANNELS = 64;
	const size_t MAX_RATES = 32;
	
	struct Channel {
		uint8_t			number;		// Channel number
		uint16_t		flags;		// Channel type flags
		enum Flags {
			supportsActiveScanning	= 0x1,
			band2GHz		= 0x2,
			band5GHz		= 0x4,
			width10MHz		= 0x8,
			width20MHz		= 0x10,
			width40MHz		= 0x20,
			requiresDFS		= 0x40,	// dynamic frequency selection for 11a
			supportsHostAPMode	= 0x80,
			supportsAdHocMode	= 0x100,
			extensionChannelIsAbove	= 0x200 // in 11n mode, if ext. ch is above this ch. (otherwise below)
		};
	};
	
	struct ChannelList {
		size_t			numItems;
		Channel			channel[MAX_CHANNELS];
	};
	
	enum DataRate {
		rateIsBasic	= 128,	// basic rates should be OR'd with this value (ie. bit 7 = 1)
		/* Rates are just uint32_t, in 0.5 Mbps units */
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
		/* Non-standard rates follow */
		rate108Mbps	= 216,	// 108 Mbps OFDM 2x clock (turbo mode)
		rate125Mbps	= 250,	// 125 Mbps OFDM (vendor proprietary or burst Tx)
		rate130Mbps	= 260,	// 130 Mbps OFDM (vendor proprietary or burst Tx)
		/* 11n MIMO rates to be added later */
	};
	
	struct RateSet {
		size_t			numItems;
		DataRate		rate[MAX_RATES];
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
			ieAll			= 256	// XXX: not defined in IEEE80211, but
							// we use it to signify all IEs as a group
		};
		uint8_t		id;		// type codes specified in enum ID
		uint8_t		length;		// length in bytes of data that follows
		uint8_t		data[0];	// variable length up to 255 bytes
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
}
}

#endif
