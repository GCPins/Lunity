#include "pch.h"
#include "MineplexBP.h"

MineplexBP::MineplexBP() : Cheat::Cheat("MineplexBP", "Other")
{
}

void MineplexBP::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			ClientInstance* clientInstance = LunMem::getClientInstance();
			LocalPlayer* localPlayer = clientInstance->LocalPlayer;
			Vector2* lookingVec = &localPlayer->LookingVec;
			MovePlayerPacket* movementPacket = new MovePlayerPacket((Actor*)localPlayer, localPlayer->getPos(), lookingVec, 0x1);
			clientInstance->LoopbackPacketSender->sendToServer(movementPacket);
		}
	}
}