/*
 *  VoodooWirelessCommand.h
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 28/07/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#ifndef _H_VOODOOWIRELESSCOMMAND_H
#define _H_VOODOOWIRELESSCOMMAND_H

#include <IOKit/IOCommand.h>

class VoodooWirelessCommand : public IOCommand {
	OSDeclareDefaultStructors(VoodooWirelessCommand)
	
public:
	bool		succeeded;
	enum CommandType {
		cmdPowerOn,
		cmdPowerOff,
		cmdStartScan,
		cmdAbortScan,
		cmdAssociate,
		cmdDisassociate,
		cmdUserAction,	// This is an arbitrary function call scheduled by the subclass
		cmdExitThread	// This 'special' command type signals the worker thread to exit
	};
	CommandType	commandType;
	void*		arg0;
	void*		arg1;
	
	static VoodooWirelessCommand* withType(CommandType cmdType, void* arg0 = 0, void* arg1 = 0);
};


#endif//_H_VOODOOWIRELESSCOMMAND_H