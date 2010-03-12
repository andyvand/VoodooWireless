/*
 *  VoodooWirelessFamily.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 14/06/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSFAMILY_H
#define _H_VOODOOWIRELESSFAMILY_H

/* Contains definitions useful in general */
enum {
	dbgFatal	= 0x1,
	dbgWarning	= 0x2,
	dbgInfo		= 0x4
};

static unsigned int org_voodoo_wireless_debug = dbgFatal;

#define DBG(level, a, b...) { if (org_voodoo_wireless_debug & level)	\
					IOLog("VoodooWireless:\t" a, ## b); }

#define DBGC(level, a, b...) { if (org_voodoo_wireless_debug & level)	\
					IOLog(a, ## b); }

#define DUMP_MBUF(mnew, rxtx)	{DBG(dbgInfo, "%s packet dump, len = %u: [ ", rxtx, mbuf_pkthdr_len(mnew));\
				uint8_t* d = (uint8_t*) mbuf_data(mnew);\
				for (int i = 0; i < mbuf_pkthdr_len(mnew); i++, d++)\
					DBGC(dbgInfo, "0x%x ", *d);\
				DBGC(dbgInfo,"]\n");}

#define __packed __attribute__((__packed__))

#define RELEASE(x)	if (x) { (x)->release(); (x) = 0; }

#endif//_H_VOODOOWIRELESSFAMILY_H