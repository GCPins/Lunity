#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Scaffold : public Cheat
{
public:
	Scaffold();
	void onGmTick(GameMode* gm);
};

