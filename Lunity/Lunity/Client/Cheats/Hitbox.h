#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Hitbox : public Cheat
{
public:
	Hitbox();
	void onTick();
	void onEnable();
	void onDisable();
};

