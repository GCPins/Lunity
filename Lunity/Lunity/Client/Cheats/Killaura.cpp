#include "pch.h"
#include "Killaura.h"
#include "../Hooks/GamemodeHook.h"

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{
	//keyBind = 0x4b;
}

void Killaura::onLoop()
{
	Cheat::onLoop();
}

void Killaura::onTick()
{
	Cheat::onTick();
	//
}

void Killaura::onEnable()
{
	Cheat::onEnable();
}

void Killaura::onDisable()
{
	Cheat::onDisable();
}

void Killaura::onKey(ulong key) {
}
