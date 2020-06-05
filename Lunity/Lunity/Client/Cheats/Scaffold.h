#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Scaffold : public Cheat
{
public:
	Scaffold();
	void onLoop();
	void onTick();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

