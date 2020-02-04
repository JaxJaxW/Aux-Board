//This file abstracts the process of dealing with car light processing
#pragma once

#include "main.h"
#include "subsystem-data-module.hpp"
#include "aux-data-module.hpp"

class LightsBoardReceive
{
	AUX_MESSAGE_0 aux0;
	AUX_MESSAGE_0_DATA_PACKET auxPacket;
public:
	LightsBoardReceive();
	void ReceiveAndSend(SUBSYSTEM_DATA_MODULE*);
};
