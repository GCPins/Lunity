#include "pch.h"
#include "Cheat.h"

Cheat::Cheat(string name, string category)
{
	this->name = name;
	this->category = category;
	Logger::log("Loaded "+name);
}

void Cheat::onLoop()
{
	if (wasEnabled != enabled) {
		if (enabled) {
			onEnable();
			Logger::log("Enabled " + name);
		}
		else {
			onDisable();
			Logger::log("Disabled " + name);
		}
		wasEnabled = enabled;
	}
	if (enabled) {
		onTick();
	}
}

void Cheat::onTick()
{
}

void Cheat::onGmLoop(GameMode* gm)
{
	if (enabled) {
		onGmTick(gm);
	}
}

void Cheat::onGmTick(GameMode* gm)
{
}

void Cheat::onEnable()
{
}

void Cheat::onDisable()
{
}

void Cheat::onKey(ulong key)
{
}

void Cheat::onPreRender()
{
}

void Cheat::onPostRender()
{
}
