#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Speed : public Cheat
{
public:
	Speed();
	void onGmTick(GameMode* gm);
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

