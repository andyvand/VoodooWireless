/*
 *  VoodooWirelessCipher_WEP.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 07/07/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSCIPHER_WEP_H
#define _H_VOODOOWIRELESSCIPHER_WEP_H

#include "VoodooWirelessCipher.h"

/* XXX: These should be in a more generic header file when net80211 is ported */
#define IEEE80211_WEP_KEYLEN            5       /* 40bit */
#define IEEE80211_WEP_IVLEN             3       /* 24bit */
#define IEEE80211_WEP_KIDLEN            1       /* 1 octet */
#define IEEE80211_WEP_CRCLEN            4       /* CRC-32 */
#define IEEE80211_WEP_TOTLEN            (IEEE80211_WEP_IVLEN + IEEE80211_WEP_KIDLEN + IEEE80211_WEP_CRCLEN)
#define IEEE80211_WEP_NKID              4       /* number of key ids */
#define IEEE80211_CRC_LEN               4

class VoodooWirelessCipher_WEP : public VoodooWirelessCipher
{
	OSDeclareDefaultStructors(VoodooWirelessCipher_WEP);

public:
	class Key : public VoodooWirelessCipherKey {
		friend class VoodooWirelessCipher_WEP;
		/* no extra data right now */
	};
	
	class Context : public VoodooWirelessCipherContext {
		friend class VoodooWirelessCipher_WEP;
	private:
		uint32_t	iv;
		Key*		key;
	};
	
	virtual bool	start(IOService* provider);
	virtual void	stop(IOService* provider);
	
	virtual VoodooWirelessCipherContext* initContext();
	virtual void	freeContext(VoodooWirelessCipherContext* ctx);
	
	virtual bool	setKey(VoodooWirelessCipherContext* ctx, VoodooWirelessCipherKey* key);
	
	virtual bool	encap(VoodooWirelessCipherContext* ctx, mbuf_t* m);
	virtual bool	decap(VoodooWirelessCipherContext* ctx, mbuf_t* m);
	virtual bool	enMIC(VoodooWirelessCipherContext* ctx, mbuf_t* m);
	virtual bool	deMIC(VoodooWirelessCipherContext* ctx, mbuf_t* m);
	
private:
	bool		wep_encrypt(Context* ctx, mbuf_t* m, size_t hdrlen);
	bool		wep_decrypt(Context* ctx, mbuf_t* m, size_t hdrlen);
};

#endif//_H_VOODOOWIRELESSCIPHER_WEP_H