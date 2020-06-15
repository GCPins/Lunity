#include "pch.h"
#include "NoSlowDown.h"

NoSlowDown::NoSlowDown() :Cheat::Cheat("NoSlowDown", "Movement")
{

}

void NoSlowDown::onEnable()
{
	Cheat::onEnable();
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0x1ABC2E9), 5);
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0xFCC546), 5);
}

void NoSlowDown::onDisable()
{
	Cheat::onDisable();
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0x1ABC2E9), (BYTE*)"\xF3\xF\x11\x46\x0C", 5);
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0xFCC546), (BYTE*)"\xF3\x0F\x11\x46\x0C", 5);
}
