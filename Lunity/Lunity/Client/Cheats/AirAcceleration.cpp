#include "pch.h"
#include "AirAcceleration.h"

float airAccelerationSpeed = 0.01f;

AirAcceleration::AirAcceleration() : Cheat::Cheat("AirAcceleration", "Movement") 
{
	registerSliderSetting("Speed", &airAccelerationSpeed, 0.f, 1.f);
}

void AirAcceleration::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->airAcceleration = airAccelerationSpeed;
		}
	}
}