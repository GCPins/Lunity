#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class NoPacket : public Cheat
{
public:
	NoPacket();
	void onPacketSend(void* Packet, PacketType type, bool* cancel);
};

