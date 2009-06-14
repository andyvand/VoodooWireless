/*
 *  VoodooWirelessDevice.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 12/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#include <IOKit/IOService.h>
#include <IOKit/network/IOEthernetController.h>

namespace org_voodoo_wireless {
	
	enum ScanType {
		scanTypeActive,
		scanTypePassive,
		scanTypeBackground
	};
	
	struct Channel {
		
	}
	
	struct ScanParameters {
		ScanType		scanType;	/* Type of scan */
		IOEthernetAddress	bssid;		/* BSSID of the network to scan for */
		OSSymbol*		ssid;		/* SSID (network name) to scan for */
		OSNumber*		dwellTime;	/* Time to stay on each channel (ms) */
		OSNumber*		restTime;	/* Time to wait between channels (ms) */
	};
	
	struct ScanResult {};
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
	
	/* Functions for establishing connections */
	virtual bool		startFullScan		( const ScanParameters* params ) = 0;
	virtual bool		startChannelScan	( const ScanParameters* params, const Channel* channel ) = 0;
};