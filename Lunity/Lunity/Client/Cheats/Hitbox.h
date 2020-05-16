#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Hitbox : public Cheat
{
public:
	Hitbox();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

