#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class NoPacket : public Cheat
{
public:
	NoPacket();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

