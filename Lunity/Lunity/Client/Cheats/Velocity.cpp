#include "pch.h"
#include "Velocity.h"

Velocity::Velocity() :Cheat::Cheat("Velocity", "Player")
{

}

void Velocity::onEnable()
{
	Cheat::onEnable();
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0x126D0C2), 6);
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0x126D0CB), 6);
	LunMem::Nop((BYTE*)(LunMem::getBaseModule() + 0x126D0D4), 6);
}

void Velocity::onDisable()
{
	Cheat::onDisable();
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0x126D0C2), (BYTE*)"\x89\x81\x94\x04\x00\x00", 6);
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0x126D0CB), (BYTE*)"\x89\x81\x98\x04\x00\x00", 6);
	LunMem::Patch((BYTE*)(LunMem::getBaseModule() + 0x126D0D4), (BYTE*)"\x89\x81\x9C\x04\x00\x00", 6);
}