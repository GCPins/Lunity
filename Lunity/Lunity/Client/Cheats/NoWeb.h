#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class NoWeb : public Cheat
{
public:
	NoWeb();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

