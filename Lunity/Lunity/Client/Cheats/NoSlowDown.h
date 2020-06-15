#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class NoSlowDown : public Cheat
{
public:
	NoSlowDown();
	void onEnable();
	void onDisable();
};

