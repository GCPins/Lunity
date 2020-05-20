#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Jetpack : public Cheat
{
public:
	Jetpack();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

