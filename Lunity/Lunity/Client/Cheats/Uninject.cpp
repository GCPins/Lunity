#include "pch.h"
#include "Uninject.h"
#include "../Hooks/KeyHook.h"
#include "../Hooks/RenderHook.h"
#include "../Hooks/GamemodeHook.h"

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
	log("Uninjecting...");
	Cheat::onEnable();
	KeyHook::uninstallHook();
	RenderHook::uninstallHook();
	GamemodeHook::uninstallHook();
	log("Hooks removed, freeing...");
	FreeLibraryAndExitThread((HMODULE)LunMem::getThisModule(), 0);
}

void Uninject::onDisable()
{
	Cheat::onDisable();
}

void Uninject::onKey(ulong key) {
}
