#include "pch.h"
#include "NoWater.h"

NoWater::NoWater() :Cheat::Cheat("NoWater", "Movement")
{

}

void NoWater::onEnable() {
	Cheat::onEnable();
	LunMem::Nop((BYTE*)LunMem::getBaseModule() + 0x127559D, 7);
}

void NoWater::onDisable() {
	Cheat::onDisable();
	LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x127559D, (BYTE*)"\xC6\x83\x15\x02\x00\x00\x01", 7);
}