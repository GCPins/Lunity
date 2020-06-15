#include "pch.h"
#include "CPULimiter.h"

float tickDelay = 1;
CPULimiter::CPULimiter() :Cheat::Cheat("CPULimiter", "Other")
{
	enabled = true;
	registerSliderSetting("Lun TDelay", &tickDelay, 0, 15);
}

void CPULimiter::onTick() {
	Sleep(tickDelay);
}