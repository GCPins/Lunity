#pragma once
#include "../Cheat.h"
class ClickGui : public Cheat
{
public:
	ClickGui();
	void onEnable();
	void onPostRender();
};

