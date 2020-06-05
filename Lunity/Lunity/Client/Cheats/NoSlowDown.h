#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class NoSlowDown : public Cheat
{
public:
	NoSlowDown();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

