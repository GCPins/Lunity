#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/KeyHook.h"
#include <chrono>

class HiveGlide : public Cheat
{
public:
	HiveGlide();
	void onTick();
	void onDisable();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

