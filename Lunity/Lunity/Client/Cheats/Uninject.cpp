#include "pch.h"
#include "Uninject.h"
#include "../Hooks/KeyHook.h"
#include "../Hooks/RenderHook.h"
#include "../Hooks/GamemodeHook.h"
#include "../Hooks/MouseHook.h"
#include "../Hooks/NetworkHook.h"

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
	Logger::log("Uninjecting...");
	Cheat::onEnable();
	KeyHook::uninstallHook();
	RenderHook::uninstallHook();
	GamemodeHook::uninstallHook();
	MouseHook::uninstallHook();
	NetworkHook::uninstallHook();
	Logger::log("Hooks removed, freeing...");
	FreeLibraryAndExitThread((HMODULE)LunMem::getThisModule(), 0);
}

void Uninject::onDisable()
{
	Cheat::onDisable();
}

void Uninject::onKey(ulong key) {
}
