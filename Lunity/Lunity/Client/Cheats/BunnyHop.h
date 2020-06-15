#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class BunnyHop : public Cheat
{
public:
	BunnyHop();
	void onGmTick(GameMode* gm);
};

