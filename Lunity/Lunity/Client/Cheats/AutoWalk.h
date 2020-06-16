#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class AutoWalk : public Cheat
{
public:
	AutoWalk();
	void onGmTick(GameMode* gm);
};

