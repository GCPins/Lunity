#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class NoWater : public Cheat
{
public:
	NoWater();
	void onEnable();
	void onDisable();
};

