#pragma once
#include "../Cheat.h"
#include <chrono>

class CCFly : public Cheat
{
public:
	CCFly();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onTick();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

