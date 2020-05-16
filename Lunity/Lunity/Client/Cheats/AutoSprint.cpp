#include "pch.h"
#include "AutoSprint.h"
#include "../KeyHook.h"

AutoSprint::AutoSprint() :Cheat::Cheat("AutoSprint", "Movement")
{

}

void AutoSprint::onLoop()
{
	Cheat::onLoop();
}

void AutoSprint::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			if (KeyHook::KeyState(0x53) | KeyHook::KeyState(0x57)) {
				player->setSprinting(true);
			}
		}
}

void AutoSprint::onEnable()
{
	Cheat::onEnable();
}

void AutoSprint::onDisable()
{
	Cheat::onDisable();
}

void AutoSprint::onKey(ulong key) {
}
