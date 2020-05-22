#pragma once
#include "../Cheat.h"
class NoFall : public Cheat
{
public:
	NoFall();
	void onPacket(void* Packet);
};

