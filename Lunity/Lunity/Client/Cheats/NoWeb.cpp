#include "pch.h"
#include "NoWeb.h"

NoWeb::NoWeb() :Cheat::Cheat("NoWeb", "Movement")
{

}

void NoWeb::onEnable()
{
	Cheat::onEnable();
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0x1264065), 8);
}

void NoWeb::onDisable()
{
	Cheat::onDisable();
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0x1264065), (BYTE*)"\xF3\x0F\x11\x89\x10\x02\x00\x00", 8);
}