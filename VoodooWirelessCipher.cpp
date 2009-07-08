/*
 *  VoodooWirelessCipher.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 07/07/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#include "VoodooWirelessCipher.h"
#define MyClass	VoodooWirelessCipher
#define super	IOService

OSDefineMetaClassAndStructors(VoodooWirelessCipher, IOService);

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

bool MyClass::encap(VoodooWirelessCipherContext* ctx, mbuf_t m)
{
	return false;
}

bool MyClass::decap(VoodooWirelessCipherContext* ctx, mbuf_t m)
{
	return false;
}

bool MyClass::enMIC(VoodooWirelessCipherContext* ctx, mbuf_t m)
{
	return false;
}

bool MyClass::deMIC(VoodooWirelessCipherContext* ctx, mbuf_t m)
{
	return false;
}

