#pragma once
#include "../Cheat.h"
class ClickGUI : public Cheat
{
public:
	ClickGUI();
	void onDisable();
	void onMouseMove();
	void onMouseButton(ulong button);
	void onMouseRelease(ulong button);
	void onPostRender();
};