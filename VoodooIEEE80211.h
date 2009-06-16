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

class VoodooIEEE80211 : public IOService {
	OSDeclareDefaultStructors(VoodooIEEE80211);
	
public:
	/* IOKit related functions */
	bool start(IOService* provider);
	void stop(IOService* provider);
	
	/* IEEE functions */

};

namespace org_voodoo_wireless {
	class IEList {
	private:
		OSOrderedSet* _set;
	public:
		virtual IEList* withData(OSData* data);
		virtual OSData* getAsData(IEEE::IE::ID which);
		virtual size_t	getNumElements();
	};
}


#endif//_H_VOODOOIEEE80211_H