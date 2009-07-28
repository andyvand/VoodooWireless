/*
 *  VoodooWirelessDevice.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 12/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#pragma mark Defines and other stuff

#include "VoodooWirelessDevice.h"
#include <IOKit/network/IOGatedOutputQueue.h>

#define MyClass	VoodooWirelessDevice

enum {
	// Flags for _flags member variable
	flagResourcesAllocated	= 1,
	flagPowerOn		= 2,
	flagInterfaceEnabled	= 4
};


//*********************************************************************************************************************
#pragma mark -
#pragma mark Basic IOKit functions
//*********************************************************************************************************************
bool
MyClass::start
( IOService* provider )
{
	_simpleLock = IOSimpleLockAlloc();
	if (_simpleLock == 0)
		return false;
	else
		return true;
}


void
MyClass::stop
( IOService* provider )
{
	if (_simpleLock)
		IOSimpleLockFree(_simpleLock);
	return;
}


// Power Management
IOReturn
MyClass::registerWithPolicyMaker
( IOService* policyMaker )
{
	static IOPMPowerState powerStateArray[ 2 ] = {
		{ 1,0,0,0,0,0,0,0,0,0,0,0 },
		{ 1,kIOPMDeviceUsable,kIOPMPowerOn,kIOPMPowerOn,0,0,0,0,0,0,0,0 }
	};
	return policyMaker->registerPowerDriver( this, powerStateArray, 2 );
}


#pragma mark -
#pragma mark Apple 802.11 ioctl
SInt32
MyClass::apple80211Request
( UInt32 request_type, int request_number, IO80211Interface* interface, void* data )
{
	return kIOReturnUnsupported;
}


#pragma mark -
#pragma mark Network driver functions
IOReturn
MyClass::enable
( IONetworkInterface* aNetif )
{
	IOSimpleLockLock(_simpleLock);		// Prevent re-entrancy
	
	if (_flags & flagInterfaceEnabled)	// Don't re-enable already enabled interface
		goto fail;
	if (!(_flags & flagResourcesAllocated))	// Make sure resources have been allocated already
		goto fail;
	
	if (turnPowerOn() != kIOReturnSuccess)
		goto fail;
	
	_flags |= flagInterfaceEnabled;
	IOSimpleLockUnlock(_simpleLock);
	return kIOReturnSuccess;
	
fail:
	IOSimpleLockUnlock(_simpleLock);
	return kIOReturnError;
}


IOReturn
MyClass::disable
( IONetworkInterface* aNetif )
{
	IOSimpleLockLock(_simpleLock);		// Prevent re-entrancy
	
	if (!(_flags & flagInterfaceEnabled))	// Don't disable already disabled interface
		goto fail;
	
	if (turnPowerOff() != kIOReturnSuccess)
		goto fail;
	
	_flags &= ~(flagInterfaceEnabled);
	IOSimpleLockUnlock(_simpleLock);
	return kIOReturnSuccess;
	
fail:
	IOSimpleLockUnlock(_simpleLock);
	return kIOReturnError;
}


IOOutputQueue*
MyClass::createOutputQueue
( )
{
	// Create a gated output queue with the 802.11 workloop, and size set to the HW's tx queue size
	return IOGatedOutputQueue::withTarget(this, getWorkLoop(), _hwInfo.txQueueSize);
}


UInt32
MyClass::outputPacket
( mbuf_t m, void* param )
{
	// Send packets to endless pit!
	freePacket(m);
	return kIOReturnOutputDropped;
}



//*********************************************************************************************************************
#pragma mark -
#pragma mark Quick implementation of tiny functions
//*********************************************************************************************************************
const OSString*	MyClass::newVendorString	( ) const	{ return _hwInfo.manufacturer; }
const OSString*	MyClass::newModelString		( ) const	{ return _hwInfo.model; }
const OSString*	MyClass::newRevisionString	( ) const	{ return _hwInfo.hardwareRevision; }

IOReturn
MyClass::getHardwareAddress
( IOEthernetAddress* addr )
{
	bcopy(_hwInfo.hardwareAddress.bytes, addr->bytes, 6);
	return kIOReturnSuccess;
}

IOReturn
MyClass::getMaxPacketSize
( UInt32 *maxSize ) const
{
	*maxSize = _hwInfo.maxPacketSize;
	return kIOReturnSuccess;
}



//*********************************************************************************************************************
// Following functions are dummy implementations but they must succeed for the network driver to work
#pragma mark -
#pragma mark Dummy functions
//*********************************************************************************************************************
IOReturn	MyClass::setPromiscuousMode	( IOEnetPromiscuousMode mode )		{ return kIOReturnSuccess; }
IOReturn	MyClass::setMulticastMode	( IOEnetMulticastMode mode )		{ return kIOReturnSuccess; }
IOReturn	MyClass::setMulticastList	( IOEthernetAddress* addr, UInt32 len )	{ return kIOReturnSuccess; }
SInt32		MyClass::monitorModeSetEnabled	( IO80211Interface * interface,
						  bool enabled, UInt32 dlt )		{ return kIOReturnSuccess; }

//*********************************************************************************************************************
// Hardware specific functions to be implemented by subclasses. Putting dummy implementations here
#pragma mark -
#pragma mark To be subclassed
//*********************************************************************************************************************
IOReturn	MyClass::allocateResources	( )					{ return kIOReturnUnsupported; }
void		MyClass::freeResources		( )					{ return; }
IOReturn	MyClass::turnPowerOn		( )					{ return kIOReturnUnsupported; }
IOReturn	MyClass::turnPowerOff		( )					{ return kIOReturnUnsupported; }
IOReturn	MyClass::startScan		( const ScanParameters* params,
						  const IEEE::ChannelList* channels )	{ return kIOReturnUnsupported; }
void		MyClass::abortScan		( )					{ return; }
IOReturn	MyClass::associate		( const AssociationParameters* params )	{ return kIOReturnUnsupported; }
IOReturn	MyClass::disasssociate		( )					{ return kIOReturnUnsupported; }
void		MyClass::getHardwareInfo	( HardwareInfo* info )			{ return; }
IOReturn	MyClass::getConfiguration	( HardwareConfigType type, void* param ){ return kIOReturnUnsupported; }
IOReturn	MyClass::setConfiguration	( HardwareConfigType type, void* param ){ return kIOReturnUnsupported; }
void		MyClass::report			( DeviceResponseMessage msg, void* arg ){ return; }
void		MyClass::inputFrame		( RxFrameHeader hdr, mbuf_t data )	{ return; }
IOReturn	MyClass::outputFrame		( TxFrameHeader hdr, mbuf_t data )	{ return kIOReturnUnsupported; }
