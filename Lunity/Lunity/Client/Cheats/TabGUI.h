#pragma once
#include "../Cheat.h"
class TabGUI : public Cheat
{
public:
	TabGUI();
	void onPostRender();
	void onKey(ulong key);
};