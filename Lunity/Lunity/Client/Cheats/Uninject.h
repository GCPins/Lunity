#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Uninject : public Cheat
{
public:
	Uninject();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

