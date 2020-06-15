#pragma once
#include "../Cheat.h"
class PacketLogger : public Cheat
{
public:
	PacketLogger();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

