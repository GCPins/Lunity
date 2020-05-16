#include "pch.h"
#include "Uninject.h"

Uninject::Uninject() :Cheat::Cheat("Uninject", "Other")
{
	//keyBind = 0x4b;
}

void Uninject::onLoop()
{
	Cheat::onLoop();
}

void Uninject::onTick()
{
	Cheat::onTick();
}

void Uninject::onEnable()
{
	Cheat::onEnable();
	FreeLibraryAndExitThread((HMODULE)LunMem::getThisModule(), 0);
}

void Uninject::onDisable()
{
	Cheat::onDisable();
}

void Uninject::onKey(ulong key) {
}
