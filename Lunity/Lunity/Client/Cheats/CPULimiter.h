#pragma once
#include "../Cheat.h"
#include "../CheatManager.h"

class CPULimiter : public Cheat {
public:
	CPULimiter();
	void onTick();
	void onPreRender();
};