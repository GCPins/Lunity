#include "pch.h"
#include "Phase.h"

Phase::Phase() : Cheat::Cheat("Phase", "Player") {

}

void Phase::onGmTick(GameMode* GM) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* localPlayer = LunMem::getClientInstance()->LocalPlayer;
			localPlayer->Pos2.y = (localPlayer->getPos()->y - (float)1.8f);
		}
	}
}

void Phase::onDisable() {
	Cheat::onDisable();

	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->Pos2.y = LunMem::getClientInstance()->LocalPlayer->getPos()->y;
		}
	}
}