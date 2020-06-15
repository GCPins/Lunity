#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class LBfly : public Cheat
{
public:
	LBfly();
	void onTick();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};