/*
 *  VoodooIEEE80211.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 14/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#include "VoodooIEEE80211.h"
#include <IOKit/IOLib.h>

OSDefineMetaClassAndStructors(VoodooIEEE80211, IOService);

bool VoodooIEEE80211::start(IOService* provider) {
	if ( !IOService::start(provider) )
		return false;
	registerService();
	return true;
}

void VoodooIEEE80211::stop(IOService* provider) {
	terminate();
	return IOService::stop(provider);
}