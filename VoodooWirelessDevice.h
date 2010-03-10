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

#include <sys/types.h>
#include <sys/kpi_mbuf.h>

#include <IOKit/IOService.h>
#include <IOKit/IOMessage.h>
#include <IOKit/IOWorkLoop.h>
#include <IOKit/IOCommandPool.h>

#include "IO80211Controller.h"
#include "IO80211Interface.h"
#include "IO80211WorkLoop.h"
#include <IOKit/network/IOOutputQueue.h>
#include <IOKit/network/IOGatedOutputQueue.h>

#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211.h"
#include "VoodooWirelessDevice_Types.h"
#include "VoodooWirelessCipher.h"

using namespace org_voodoo_wireless;

class VoodooWirelessDevice : public IO80211Controller
{
	OSDeclareDefaultStructors(VoodooWirelessDevice)
public:
	/* NOTE: None of the public functions need to be implemented by subclasses. Proper implementations
	 *       is already provided by this superclass */
	
	/* Basic IOKit functions */
	virtual bool		start			( IOService* provider );
	virtual void		stop			( IOService* provider );
	IOReturn		registerWithPolicyMaker	( IOService* policyMaker );
	
	/* Network driver and apple80211 functions */
	SInt32			apple80211Request	( UInt32 request_type, int request_number,
							  IO80211Interface* interface, void* data );
	IOReturn		enable			( IONetworkInterface* aNetif );
	IOReturn		disable			( IONetworkInterface* aNetif );
	IOOutputQueue*		createOutputQueue	( );
	
	UInt32			outputPacket		( mbuf_t m, void* param );

	IOReturn		getMaxPacketSize	( UInt32 *maxSize ) const;
	const OSString*		newVendorString		( ) const;
	const OSString*		newModelString		( ) const;
	const OSString*		newRevisionString	( ) const;
	IOReturn		getHardwareAddressForInterface( IO80211Interface* netif, IOEthernetAddress* addr );
	IOReturn		getHardwareAddress	( IOEthernetAddress* addr );
	virtual IOReturn	setPromiscuousMode	( IOEnetPromiscuousMode mode );
	virtual IOReturn	setMulticastMode	( IOEnetMulticastMode mode );
	virtual IOReturn	setMulticastList	( IOEthernetAddress* addr, UInt32 len );
	virtual SInt32		monitorModeSetEnabled	( IO80211Interface * interface, bool enabled, UInt32 dlt );
	
protected:
	struct ExpansionData {};		// reserved, for internal use only
	ExpansionData*		reserved;	// reserved, for internal use only
	
	/* Functions to init / shutdown the HW */
	virtual IOReturn	allocateResources	( IOService* provider ); // Allocate hw rings, memory etc. needed for power up
	virtual void		freeResources		( IOService* provider ); // Undo all allocations done in allocateResources()
	virtual IOReturn	turnPowerOn		( );	// Make the card ready for action
	virtual IOReturn	turnPowerOff		( );	// Turn the card off
	
	/* Functions for establishing connections, scanning etc. */
	virtual IOReturn	startScan		( const ScanParameters* params,
							  const IEEE::ChannelList* channels );
	
	virtual void		abortScan		( );
	virtual IOReturn	associate		( const AssociationParameters* params );
	virtual IOReturn	disassociate		( );
	
	/* Various configuration functions */
	virtual void		getHardwareInfo		( HardwareInfo* info );
	virtual IOReturn	getConfiguration	( HardwareConfigType type, void* param );
	virtual IOReturn	setConfiguration	( HardwareConfigType type, void* param );
	
	/* The following function should be called by subclasses to report events. */
	void			report			( DeviceResponseMessage msg, void* arg = 0 );
	
	/* This is to be called by subclasses when it receives any frames from HW.
	 * "data" should be raw 802.11 frame.
	 * During scanning, beacon or probe response frames should be passed via this function
	 */
	void			inputFrame		( RxFrameHeader hdr, mbuf_t data );
	
	/* This function must be implemented by the subclass to output a raw 802.11 frame.
	 * Note that the mbuf_t could either be a single mbuf or a chain of 2 or more mbufs.
	 * The passed mbuf_t becomes property of the driver which should free it when it is no longer needed.
	 */
	virtual IOReturn	outputFrame		( TxFrameHeader hdr, mbuf_t data );
	
private:
	HardwareInfo		_hwInfo;
	uint32_t		_flags;
	IOLock*			_lock;
	uint8_t			_staState;
	IEEE::ReasonCode	_lastReasonCode;
	IONetworkMedium*	_medium;
	IO80211Interface*	_netif;
	IOGatedOutputQueue*	_queue;
	IO80211WorkLoop*	_workloop;
	IOCommandPool*		_commandPool;
	OSArray*		_scanResults;
	uint32_t		_totalResultsInCurrentScan;
	uint32_t		_resultsPending;
	apple80211_scan_result	_currentNetwork;
	apple80211_assoc_data	_currentAssocData;
	uint8_t			_currentChannel;
	int			_currentNoiseLevel;
	int			_currentSignalLevel;
	RxFrameHeader		_lastRxFrameHeader;
	
	VoodooWirelessCipher*		_cipher;
	VoodooWirelessCipherKey		_cipherKey;
	VoodooWirelessCipherContext*	_cipherContext;
	
	int			todBm(int val);
	void			workerThread(void* arg);
	void			handleScanResultFrame(RxFrameHeader hdr, mbuf_t m);
	IOReturn		probeResponseToScanResult(RxFrameHeader hdr, mbuf_t m, apple80211_scan_result* ret);
	bool			scanResultsAreSimilar(const apple80211_scan_result* a, const apple80211_scan_result* b);
	apple80211_scan_result*	findScanResult(apple80211_assoc_data* a);
	void			setPowerOn();
	void			setPowerOff();
	void			setLinkUp();
	void			setLinkDown();
	
	IOReturn		apple80211Request_GET(int request_number, void* data);
	IOReturn		apple80211Request_SET(int request_number, void* data);
	
	IOReturn		enqueueCommand(uint32_t commandType, void* arg0 = 0, void* arg1 = 0);
	
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