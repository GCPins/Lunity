#pragma once
#include "../Cheat.h"
class ClickGui : public Cheat
{
public:
	ClickGui();
	void onMouseButton(ulong button);
	void onMouseMove();
	void onEnable();
	void onPostRender();
};

