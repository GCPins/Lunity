#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class AirJump: public Cheat
{
public:
	AirJump();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
};

