#include "pch.h"
#include "AutoSprint.h"
#include "../Hooks/KeyHook.h"

AutoSprint::AutoSprint() :Cheat::Cheat("AutoSprint", "Movement")
{

}

void AutoSprint::onGmTick(GameMode* gm)
{
	Cheat::onTick();

	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* localPlayer = LunMem::getClientInstance()->LocalPlayer;
			localPlayer->setSprinting(true);
		}
	}
}
