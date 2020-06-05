#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/KeyHook.h"

class WarpShift : public Cheat
{
public:
	WarpShift();
	void onTick();
	void onEnable();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

