#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Spinbot : public Cheat
{
public:
	Spinbot();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

