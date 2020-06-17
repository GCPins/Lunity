#include "pch.h"
#include "Flight.h"

Flight::Flight() : Cheat::Cheat("Flight", "Player") {

}

void Flight::onGmTick(GameMode* GM) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->isFlying = 0x1;
		}
	}
}

void Flight::onDisable() {
	Cheat::onDisable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->isFlying = 0x0;
		}
	}
}