#pragma once
#include "../Cheat.h"
class Profiler : public Cheat
{
public:
	Profiler();
	void onEnable();
	void onPostRender();
};

