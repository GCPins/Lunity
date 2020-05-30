#pragma once
#include "../Cheat.h"
class PacketLogger : public Cheat
{
public:
	PacketLogger();
	void onEnable();
	void onTick();
	void onGmTick(GameMode* gm);
	void onPacketSend(void* Packet, PacketType type, bool* cancel);
};

