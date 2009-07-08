/*
 *  VoodooWirelessCipher.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 06/07/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSCIPHER_H
#define _H_VOODOOWIRELESSCIPHER_H

#include <IOKit/IOService.h>
#include <sys/kpi_mbuf.h>

#define IEEE80211_KEYBUF_SIZE		(32+8+8) // Enough space for all types of keys + MICs

/* Cipher types */
#define IEEE80211_CIPHER_WEP		0
#define IEEE80211_CIPHER_TKIP		1
#define IEEE80211_CIPHER_AES_OCB	2
#define IEEE80211_CIPHER_AES_CCM	3
#define IEEE80211_CIPHER_TKIPMIC	4       /* TKIP MIC capability */
#define IEEE80211_CIPHER_CKIP		5
#define IEEE80211_CIPHER_PASSTHRU	6	/* identity cipher. just passes input to output */
#define IEEE80211_CIPHER_NULL		7	/* for the base class */

class VoodooWirelessCipherKey		// to be derived from
{
	friend class VoodooWirelessCipher;
public:
	size_t	keyLength;
	uint8_t	key[IEEE80211_KEYBUF_SIZE];
	/* ... subclassed key types can add their own public or private data */
};

class VoodooWirelessCipherContext	// to be derived from
{
	friend class VoodooWirelessCipher;
};



class VoodooWirelessCipher : public IOService
{
	OSDeclareDefaultStructors(VoodooWirelessCipher)
	
protected:
	struct ExpansionData {};	// reserved, for internal use only
	ExpansionData*	reserved;	// reserved, for internal use only
	
	struct Info {
		uint8_t	cipherType;	// check #defines above
		char*	cipherName;	// (short) name of the cipher
		size_t	headerSize;	// size of privacy header (in bytes)
		size_t	trailerSize;	// size of privacy trailer (in bytes)
		size_t	micSize;	// size of MIC trailer (in bytes)
	};
	
	Info		_cipherInfo;
	
public:
	virtual bool	start(IOService* provider);
	virtual void	stop(IOService* provider);
	
	virtual Info	getInfo() const;				/* Return the cipher's information */
	
	/* This function creates a new context for this cipher and returns it */
	virtual VoodooWirelessCipherContext* initContext();
	
	/* This function destroys an existing cipher context */
	virtual void	freeContext(VoodooWirelessCipherContext* ctx);
	
	/* NOTE: The following functions return true on success, false on failure */
	virtual bool	setKey(VoodooWirelessCipherContext* ctx, VoodooWirelessCipherKey* key);
	
	virtual bool	encap(VoodooWirelessCipherContext* ctx, mbuf_t m);
	virtual bool	decap(VoodooWirelessCipherContext* ctx, mbuf_t m);
	virtual bool	enMIC(VoodooWirelessCipherContext* ctx, mbuf_t m);
	virtual bool	deMIC(VoodooWirelessCipherContext* ctx, mbuf_t m);
	
private:
	/* The following are reserved slots for future expansion */
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 0);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 1);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 2);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 3);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 4);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 5);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 6);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 7);
	OSMetaClassDeclareReservedUsed(VoodooWirelessCipher, 8);
};

#endif//_H_VOODOOWIRELESSCIPHER_H