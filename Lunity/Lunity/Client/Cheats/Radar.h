#pragma once
#include "../Cheat.h"
class Radar : public Cheat
{
public:
	Radar();
	void onMouseButton(ulong button);
	void onPostRender();
};

