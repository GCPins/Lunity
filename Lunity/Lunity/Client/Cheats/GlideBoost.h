#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/KeyHook.h"

class GlideBoost : public Cheat
{
public:
	GlideBoost();
	void onTick();
	void onEnable();
	void onDisable();
	void onPacketSend(void* Packet, PacketType type, bool* cancel);
};

