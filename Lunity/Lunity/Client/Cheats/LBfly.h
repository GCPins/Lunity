#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class LBfly : public Cheat
{
public:
	LBfly();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onGamemodeTick(GameMode* GM);
	void onPacket(void* Packet, PacketType type, bool* cancel);
};