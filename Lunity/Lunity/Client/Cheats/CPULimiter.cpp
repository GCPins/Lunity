#include "pch.h"
#include "CPULimiter.h"

CPULimiter::CPULimiter() :Cheat::Cheat("CPULimiter", "Other")
{

}

void CPULimiter::onLoop() {
	CheatManager::cpuLimiter = enabled;
}