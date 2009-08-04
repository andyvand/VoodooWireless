/*
 *  VoodooWirelessCommand.cpp
 *  VoodooWireless
 *
 *  Created by Prashant Vaibhav on 04/08/09.
 *  Copyright 2009 Prashant Vaibhav. All rights reserved.
 *
 */

#include "VoodooWirelessCommand.h"

OSDefineMetaClassAndStructors(VoodooWirelessCommand, IOCommand)

VoodooWirelessCommand* VoodooWirelessCommand::withType
( VoodooWirelessCommand::CommandType cmdType, void* arg0, void* arg1 )
{
	VoodooWirelessCommand* cmd = new VoodooWirelessCommand;
	if (!cmd) return 0;
	cmd->commandType = cmdType;
	cmd->arg0 = arg0;
	cmd->arg1 = arg1;
	return cmd;
}