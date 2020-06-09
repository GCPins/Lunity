#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class Criticals : public Cheat
{
public:
	Criticals();
	void onEnable();
	void onDisable();
	void onPacket(void* Packet, PacketType type, bool* cancel);
};