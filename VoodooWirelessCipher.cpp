/*
 *  VoodooWirelessCipher.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 07/07/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#include <IOKit/IOLib.h>
#include "VoodooWirelessCipher.h"

#define MyClass	VoodooWirelessCipher
#define super	IOService

OSDefineMetaClassAndStructors(VoodooWirelessCipher, IOService);

OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 0);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 1);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 2);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 3);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 4);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 5);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 6);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 7);
OSMetaClassDefineReservedUnused(VoodooWirelessCipher, 8);


bool MyClass::start(IOService* provider) {
	if (super::start(provider) == false)
		return false;
	_cipherInfo.cipherType	= IEEE80211_CIPHER_NULL;
	_cipherInfo.cipherName	= "NULL";
	_cipherInfo.headerSize	= 0;
	_cipherInfo.trailerSize	= 0;
	_cipherInfo.micSize	= 0;
	return true;
}

void MyClass::stop(IOService* provider) {
	super::stop(provider);
	IOLog("Unregistered VoodooWireless crypto module: %s\n", _cipherInfo.cipherName);
}

void MyClass::registerService(IOOptionBits options) {
	super::registerService(options);
	
	/* Set cipher properties in the IORegistry, which will be used to find it */
	setProperty(CIPHER_PROPERTY_NAME,	_cipherInfo.cipherName);
	/*
	setProperty(CIPHER_PROPERTY_TYPE,	_cipherInfo.cipherType);
	setProperty(CIPHER_PROPERTY_MICSIZE,	_cipherInfo.micSize);
	setProperty(CIPHER_PROPERTY_HEADERSIZE,	_cipherInfo.headerSize);
	setProperty(CIPHER_PROPERTY_TRAILERSIZE,_cipherInfo.trailerSize);
	*/
	IOLog("Registered VoodooWireless crypto module: %s\n", _cipherInfo.cipherName);
}

MyClass::Info MyClass::getInfo() const {
	return _cipherInfo;
}

VoodooWirelessCipherContext* MyClass::initContext()
{
	return 0;
}

void MyClass::freeContext(VoodooWirelessCipherContext* ctx)
{
	return;
}

bool MyClass::setKey(VoodooWirelessCipherContext* ctx, VoodooWirelessCipherKey* key)
{
	return false;
}

bool MyClass::encap(VoodooWirelessCipherContext* ctx, mbuf_t* m)
{
	return false;
}

bool MyClass::decap(VoodooWirelessCipherContext* ctx, mbuf_t* m)
{
	return false;
}

bool MyClass::enMIC(VoodooWirelessCipherContext* ctx, mbuf_t* m)
{
	return false;
}

bool MyClass::deMIC(VoodooWirelessCipherContext* ctx, mbuf_t* m)
{
	return false;
}

