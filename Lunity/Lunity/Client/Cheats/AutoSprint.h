#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class AutoSprint : public Cheat
{
public:
	AutoSprint();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

