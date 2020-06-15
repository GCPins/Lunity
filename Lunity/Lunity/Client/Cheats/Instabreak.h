#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Instabreak : public Cheat
{
public:
	Instabreak();
	void onGmTick(GameMode* gm);
};

