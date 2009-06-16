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
#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211.h"
#include "VoodooWirelessDevice_Types.h"

using namespace org_voodoo_wireless;

class VoodooWirelessDevice : public IOService
{
	
protected:
	/* Data members */
	
	struct ExpansionData {			// reserved, for internal use only
	};
	ExpansionData*		reserved;	// reserved, for internal use only
	
	/* This is to be called by subclasses when it receives any frames from HW. "data" should be raw 802.11 frame */
	void			incomingFrame		(RxFrameHeader hdr, mbuf_t data);
	
	/* The following function should be called by subclasses to report events.
	   They will be relayed to clients by the superclass as appropriate */
	void			report			(DeviceResponseMessage msg, void* arg);
	
	/* This function should be implemented by the subclass to output a raw 802.11 frame */
	virtual IOReturn	txRawFrame		(mbuf_t m) = 0;
	
public:
	/* The public functions are intended to be used by the clients of this class */
	/* Functions to init / shutdown the HW */
	virtual bool		allocateResources	( ) = 0;
	virtual void		freeResources		( ) = 0;
	virtual bool		turnPowerOn		( ) = 0;
	virtual bool		turnPowerOff		( ) = 0;
	
	/* Functions for establishing connections etc. */
	virtual bool		startScan		(const ScanParameters* params,
							 const IEEE::ChannelList* channels) = 0;
	
	virtual bool		startChannelScan	(const ScanParameters* params,
							 const Channel* channel) = 0;
	
	virtual bool		abortScan		( ) = 0;
	
	/* Following is optionally overridden by subclasses. Return value = number of results (could be zero) */
	virtual int		getScanResults		(ScanResult* results);
	
	virtual bool		associate		(const AssociationParameters* params) = 0;
	
	virtual bool		disasssociate		( ) = 0;
	
	/* Various configuration functions */
	virtual void		getHardwareInfo		(HardwareInfo* info) = 0;
	virtual unsigned int	getTxPower		( ) = 0;	// in percent
	virtual bool		setTxPower		(unsigned int power); // in percent
	
	/* Functions to send out data (NOT TO BE IMPLEMENTED by derived classes) */
	IOReturn		txRaw80211Frame		(mbuf_t m);	// transmit a fully formed raw 802.11 frame
	IOReturn		txData			(mbuf_t m);	// transmit an ethernet frame
	
	virtual IEEE::DataRate	getCurrentTxRate	( );		// optionally implementable by hardware
	
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