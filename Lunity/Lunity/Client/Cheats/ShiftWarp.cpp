#include "pch.h"
#include "ShiftWarp.h"
#include <random>

ShiftWarp::ShiftWarp() : Cheat::Cheat("ShiftWarp", "Movement")
{
}

void ShiftWarp::onEnable() {
	Cheat::onEnable();
}

void ShiftWarp::onDisable() {
	Cheat::onDisable();
}

float randomFloat() {
	vector<std::string> str;
	for (int I = 0; I < 10; I++) {
		str.push_back(to_string(I));
	}
	for (int I = 0; I > -10; I--) {
		str.push_back(to_string(I));
	}
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return std::stof(str[0]);
}

void ShiftWarp::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			ClientInstance* clientInstance = LunMem::getClientInstance();
			LocalPlayer* localPlayer = clientInstance->LocalPlayer;
			Vector2* lookingVec = &localPlayer->LookingVec;
			float randomX = floor(randomFloat());
			float randomZ = floor(randomFloat());
			Vector3 currentPos = *localPlayer->getPos();
			currentPos.x + randomX;
			currentPos.z + randomZ;
			MovePlayerPacket* movementPacket = new MovePlayerPacket((Actor*)localPlayer, &currentPos, lookingVec, 0x1);
			clientInstance->LoopbackPacketSender->sendToServer(movementPacket);
		}
	}
}