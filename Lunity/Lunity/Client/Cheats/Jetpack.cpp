#pragma once
#include "pch.h"
#include "Jetpack.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float jetpackSpeed = 1.0f;

Jetpack::Jetpack() :Cheat::Cheat("Jetpack", "Movement")
{
	enabled = true;
}

void Jetpack::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
		if (Player != NULL) {
			if (KeyHook::KeyState(0x46)) {
				Vector2 lookingVec = Player->LookingVec;
				Player->VelocityXYZ.x = cos((lookingVec.y + 90.0f) * (PI / 180.0f)) * jetpackSpeed;
				Player->VelocityXYZ.y = sin((lookingVec.x) * -(PI / 180.0f)) * jetpackSpeed;
				Player->VelocityXYZ.z = sin((lookingVec.y + 90.0f) * (PI / 180.0f)) * jetpackSpeed;
			}
		}
	}
}
