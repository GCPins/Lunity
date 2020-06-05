#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Nuker : public Cheat
{
public:
	Nuker();
	void onLoop();
	void onTick();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

