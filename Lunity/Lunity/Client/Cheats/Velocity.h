#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Velocity : public Cheat
{
public:
	Velocity();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

