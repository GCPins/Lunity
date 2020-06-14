#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class Freecam : public Cheat
{
public:
	Freecam();
	void onEnable();
	void onDisable();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};

