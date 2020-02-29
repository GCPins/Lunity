#pragma once
#include "AirJump.h"
#include "..\Cheat.h"

class AirJump : public Cheat
{
public:
	AirJump() : Cheat("AirJump", true, 0x07){}
	virtual void onTick() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
};