#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class NoFall : public Cheat
{
public:
	NoFall();
	void onTick();
};

