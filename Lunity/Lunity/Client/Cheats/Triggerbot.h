#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Triggerbot : public Cheat
{
public:
	Triggerbot();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

