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

namespace org_voodoo_wireless {
	IEList::IEList() {
		_data = 0;
	}
	
	IEList::~IEList() {
		if (_data) _data->release();
	}
	
	IEList* IEList::withData(OSData* data) {
		IEList* newInst = new IEList();
		if (newInst == 0)
			return 0;
		else {
			newInst->_data = data;
			newInst->_data->retain(); 
			return newInst;
		}
	}
	
	OSData* IEList::get(IEEE::IE::ID which) {
		if (_data == 0)
			return 0;
		/* 
		 * Scan the data, skipping over other IEs to find the one we need.
		 * Yes, this is inefficient, but it's simple.
		 */
		uint8_t* data = (uint8_t*) _data->getBytesNoCopy();
		int offset = 0;
		
		while (offset < _data->getLength()) {
			if (*(data + offset) == which)
				return OSData::withBytes(data+offset, *(data+offset+1));
			else
				offset += *(data + offset + 1); // format of each IE is Type-Length-Bytes
		};
		/* IE not found */
		return 0;
	}
	
	OSData* IEList::getRawAsData() {
		if (_data)
			return OSData::withData(_data);
		else
			return 0;
	}
}