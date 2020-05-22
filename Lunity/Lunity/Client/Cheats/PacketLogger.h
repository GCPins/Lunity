#pragma once
#include "../Cheat.h"
class PacketLogger : public Cheat
{
public:
	PacketLogger();
	void onEnable();
	void onTick();
	void onGmTick(GameMode* gm);
	void onPacket(void* Packet, PacketType type);
};

