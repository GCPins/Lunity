#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class BunnyHop : public Cheat
{
public:
	BunnyHop();
	void onLoop();
	void onGmTick(GameMode* gm);
	//void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

