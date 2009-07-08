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
	
	/* The following function should be called by subclasses to report events.
	 They will be relayed to clients by the superclass as appropriate */
	void			report			(DeviceResponseMessage msg, void* arg);
	
	/* This is to be called by subclasses when it receives any frames from HW. "data" should be raw 802.11 frame */
	void			rx80211Frame		(RxFrameHeader hdr, mbuf_t data);
	
	/* This function must be implemented by the subclass to output a raw 802.11 frame */
	virtual IOReturn	tx80211Frame		(TxFrameHeader hdr, mbuf_t data) = 0;
	
	/* This function can optionally be implemented by subclass if it wants to handle data frame tx itself */
	virtual IOReturn	txDataFrame		(TxFrameHeader hdr, mbuf_t data);
	
public:
	/* The public functions are intended to be used by the clients of this class */
	/* Functions to init / shutdown the HW */
	virtual IOReturn	allocateResources	( ) = 0;
	virtual void		freeResources		( ) = 0;
	virtual IOReturn	turnPowerOn		( ) = 0;
	virtual IOReturn	turnPowerOff		( ) = 0;
	
	/* Functions for establishing connections etc. */
	virtual IOReturn	startScan		(const ScanParameters* params,
							 const IEEE::ChannelList* channels) = 0;
	
	virtual IOReturn	abortScan		( ) = 0;
	
	/* Following can be optionally overridden by subclasses, otherwise superclass will
	   implement this to return scan results harvested from received probe responses.
	   Return value = number of results (could be zero) */
	virtual int		getScanResults		(ScanResult* results);
	
	virtual IOReturn	associate		(const AssociationParameters* params) = 0;
	
	virtual IOReturn	disasssociate		( ) = 0;
	
	/* Various configuration functions */
	virtual void		getHardwareInfo		(HardwareInfo* info) = 0;
	virtual IOReturn	getConfiguration	(HardwareConfigType type, void* param);
	virtual IOReturn	setConfiguration	(HardwareConfigType type, void* param);
	
	/* Functions to send out data (NOT TO BE IMPLEMENTED by derived classes) */
	IOReturn		txRaw80211Frame		(mbuf_t m);	// transmit a fully formed raw 802.11 frame
	IOReturn		txData			(mbuf_t m);	// transmit an ethernet frame
	
	/* Other misc. functions */
	virtual IOWorkLoop*	getWorkLoop		( );		// can be optionally overriden
	
private:
	/* The following are reserved slots for future expansion */
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 0);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 1);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 2);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 3);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 4);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 5);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 6);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 7);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 8);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 9);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 10);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 11);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 12);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 13);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 14);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 15);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 16);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 17);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 18);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 19);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 20);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 21);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 22);
	OSMetaClassDeclareReservedUsed(VoodooWirelessDevice, 23);
};

#endif//_H_VOODOOWIRELESSDEVICE_H