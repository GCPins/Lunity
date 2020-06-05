#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Speed : public Cheat
{
public:
	Speed();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

