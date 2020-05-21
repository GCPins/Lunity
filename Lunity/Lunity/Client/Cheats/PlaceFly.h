#pragma once
#include "../Cheat.h"
class PlaceFly : public Cheat
{
public:
	PlaceFly();
	void onEnable();
	void onGmTick(GameMode* gm);
};

