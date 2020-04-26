#pragma once
#include "../BigHead.h"
class Cheat
{
public:
	string name;
	bool enabled = false;
	bool wasEnabled = false;
	Cheat(string name);
	virtual void onLoop();
	virtual void onTick();
	virtual void onEnable();
	virtual void onDisable();
};

