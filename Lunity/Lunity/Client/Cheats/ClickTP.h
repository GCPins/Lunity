#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class ClickTP : public Cheat
{
public:
	ClickTP();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

