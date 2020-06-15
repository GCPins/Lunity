#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Gamemode: public Cheat
{
public:
	Gamemode();
	void onGmTick(GameMode* gm);
	void onDisable();
	void onEnable();
};

