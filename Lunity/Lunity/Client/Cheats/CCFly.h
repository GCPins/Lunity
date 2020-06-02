#pragma once
#include "../Cheat.h"
class CCFly : public Cheat
{
public:
	CCFly();
	void onGmTick(GameMode* gm);
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

