/*
 *  VoodooIEEE80211.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 14/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOIEEE80211_H
#define _H_VOODOOIEEE80211_H

#include <IOKit/IOService.h>
#include <libkern/c++/OSData.h>
#include <libkern/c++/OSOrderedSet.h>
#include "VoodooWirelessFamily.h"
#include "VoodooIEEE80211_Types.h"

namespace org_voodoo_wireless {
	class IEList {
	private:
		OSData* _data;
		IEList(); // constructor
	public:
		virtual ~IEList(); // destructor
		/* Factory method to create new IEList using OSData */
		static IEList* withData(OSData* data);
		/* Return an IE's data as OSData */
		virtual OSData* get(IEEE::IE::ID which);
		virtual OSData* getRawAsData();
	};
}


#endif//_H_VOODOOIEEE80211_H