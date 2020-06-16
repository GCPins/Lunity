#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include <chrono>
#include <algorithm>

class Killaura : public Cheat
{
public:
	Killaura();
	void onGmTick(GameMode* gm);
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

