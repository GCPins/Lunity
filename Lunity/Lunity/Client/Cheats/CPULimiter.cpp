#include "pch.h"
#include "CPULimiter.h"

float tickDelay = 1;
float renDelay = 0;
CPULimiter::CPULimiter() :Cheat::Cheat("CPULimiter", "Other")
{
	enabled = true;
	registerSliderSetting("Lun TDelay", &tickDelay, 0, 15);
	registerSliderSetting("Ren Delay", &renDelay, 0, 15);
}

void CPULimiter::onTick() {
	Sleep(tickDelay);
}

void CPULimiter::onPreRender() {
	if (enabled) {
		Sleep(renDelay);
	}
}