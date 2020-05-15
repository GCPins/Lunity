#include "pch.h"
#include "Cheat.h"

Cheat::Cheat(string name)
{
	this->name = name;
	log("Loaded "+name);
}

void Cheat::onLoop()
{
	if (wasEnabled != enabled) {
		if (enabled) {
			onEnable();
			log("Enabled " + name);
		}
		else {
			onDisable();
			log("Disabled " + name);
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

void Cheat::onEnable()
{
}

void Cheat::onDisable()
{
}

void Cheat::onKey(ulong key)
{
}
