#pragma once
#include "..\pch.h"
#include <string>

class Cheat
{
public:
	std::string name;
	bool enabled;
	Cheat();
	void onLoop();
	virtual void onTick();
	virtual void onEnable();
	virtual void onDisable();
};

