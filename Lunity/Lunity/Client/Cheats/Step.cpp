#include "pch.h"
#include "Step.h"

Step::Step() : Cheat::Cheat("Step", "Movement") {

}

void Step::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->stepHeight = (float)2.f;
		}
	}
}

void Step::onDisable() {
	Cheat::onDisable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->stepHeight = (float)0.5625f;
		}
	}
}