#pragma once
#include "pch.h"
#include "Jetpack.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float jetpackSpeed = 1.0f;
float jetpackSpeedMul = 1.0f;

Jetpack::Jetpack() :Cheat::Cheat("Jetpack", "Movement")
{
	enabled = true;
	registerSliderSetting("Speed", &jetpackSpeed, 0.f, 10.0f);
	registerSliderSetting("Multiplier", &jetpackSpeedMul, 0.f, 10.0f);
}

void Jetpack::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
		if (Player != NULL) {
			if (KeyHook::KeyState(0x46)) {
				Vector2 lookingVec = Player->LookingVec;
				float actualSpeed = jetpackSpeed * jetpackSpeedMul;
				Player->VelocityXYZ.x = cos((lookingVec.y + 90.0f) * (PI / 180.0f)) * actualSpeed;
				Player->VelocityXYZ.y = sin((lookingVec.x) * -(PI / 180.0f)) * actualSpeed;
				Player->VelocityXYZ.z = sin((lookingVec.y + 90.0f) * (PI / 180.0f)) * actualSpeed;
			}
		}
	}
}
