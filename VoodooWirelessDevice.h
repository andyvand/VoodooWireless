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
#include <IOKit/IOWorkLoop.h>
#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211.h"
#include "VoodooWirelessDevice_Types.h"

using namespace org_voodoo_wireless;

class VoodooWirelessDevice : public IOService
{
protected:
	struct ExpansionData {};		// reserved, for internal use only
	ExpansionData*		reserved;	// reserved, for internal use only
	
	/* Functions to init / shutdown the HW */
	virtual IOReturn	allocateResources	( );	// Allocate hw rings, memory etc. needed for power up
	virtual void		freeResources		( );	// Undo all allocations done in allocateResources()
	virtual IOReturn	turnPowerOn		( );	// Make the card ready for action
	virtual IOReturn	turnPowerOff		( );	// Turn the card off
	
	/* Functions for establishing connections, scanning etc. */
	virtual IOReturn	startScan		(const ScanParameters* params,
							 const IEEE::ChannelList* channels);
	
	virtual void		abortScan		( );
	
	/* Following can be optionally overridden by subclasses, otherwise superclass will
	   implement this to return scan results harvested from received probe responses.
	   Return value = number of results (could be zero) */
	virtual int		getScanResults		(ScanResult* results);
	
	virtual IOReturn	associate		(const AssociationParameters* params);
	
	virtual IOReturn	disasssociate		( );
	
	/* Various configuration functions */
	virtual void		getHardwareInfo		(HardwareInfo* info);
	virtual IOReturn	getConfiguration	(HardwareConfigType type, void* param);
	virtual IOReturn	setConfiguration	(HardwareConfigType type, void* param);
	
	/* The following function should be called by subclasses to report events.
	   They will be relayed to Airport by the superclass as appropriate */
	void			report			(DeviceResponseMessage msg, void* arg);
	
	/* This is to be called by subclasses when it receives any frames from HW. "data" should be raw 802.11 frame */
	void			frameReceived		(RxFrameHeader hdr, mbuf_t data);
	
	/* This function should be called *instead of* the previous, if the subclass wants to pass ethernet frames */
	void			ethernetFrameReceived	(RxFrameHeader hdr, mbuf_t data);
	
	/* This function must be implemented by the subclass to output a raw 802.11 frame */
	virtual IOReturn	outputFrame		(TxFrameHeader hdr, mbuf_t data);
	
	/* This function can optionally be implemented by subclass if it wants to handle Ethernet frame tx itself */
	virtual IOReturn	outputEthernetFrame	(TxFrameHeader hdr, mbuf_t data);	
	
private:
	/* The following are reserved slots for future expansion */
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 0);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 1);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 2);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 3);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 4);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 5);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 6);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 7);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 8);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 9);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 10);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 11);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 12);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 13);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 14);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 15);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 16);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 17);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 18);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 19);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 20);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 21);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 22);
	OSMetaClassDeclareReservedUnused(VoodooWirelessDevice, 23);
};

#endif//_H_VOODOOWIRELESSDEVICE_H