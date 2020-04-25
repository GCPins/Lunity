#pragma once
#include "../SDK/LunMC.h"
#include "../SDK/LunMem.h"
class Cheat
{
public:
	Cheat();
	virtual void onLoop();
	virtual void onTick();
	virtual void onEnable();
	virtual void onDisable();
};

