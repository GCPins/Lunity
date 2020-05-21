#pragma once
#include "pch.h"
#include "PlaceFly.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float placeFlySpeed = 1.0f;

PlaceFly::PlaceFly() : Cheat::Cheat("PlaceFly", "Movement")
{
}

void PlaceFly::onEnable()
{
}

//bool add = true;
void PlaceFly::onGmTick(GameMode* gm) {
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	Player->setSitting(true);
	//Player->startSwimming();
	if (KeyHook::KeyState(0x46)) {
		Vector2 lookingVec = Player->LookingVec;
		Player->VelocityXYZ.x = cos((lookingVec.y + 90.0f) * (PI / 180.0f)) * placeFlySpeed;
		Player->VelocityXYZ.y = sin((lookingVec.x) * -(PI / 180.0f)) * placeFlySpeed;
		Player->VelocityXYZ.z = sin((lookingVec.y + 90.0f) * (PI / 180.0f)) * placeFlySpeed;
	}
	
}