#pragma once
#include "../Cheat.h"
class CCGodMode : public Cheat
{
public:
	CCGodMode();
	void onTick();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

