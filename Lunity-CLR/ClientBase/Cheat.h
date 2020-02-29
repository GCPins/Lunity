#pragma once
#include "SDK/McSDK.h"
#include <string>

class Cheat
{
public:
	std::string name = "";
	bool enabled = false;
	char keybind = 0x0;
	Cheat(std::string name, bool enabled, char keybind);
	void onLoop();
	virtual void onTick();
	virtual void onEnable();
	virtual void onDisable();
};

