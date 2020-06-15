#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Gamemode: public Cheat
{
public:
	Gamemode();
	void onTick();
	void onDisable();
	void onEnable();
};

