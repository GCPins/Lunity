#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Glide : public Cheat
{
public:
	Glide();
	void onGmTick(GameMode* gm);
};

