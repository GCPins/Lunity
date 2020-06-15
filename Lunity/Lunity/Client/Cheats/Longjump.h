#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class Longjump : public Cheat
{
public:
	Longjump();
	void onTick();
};

