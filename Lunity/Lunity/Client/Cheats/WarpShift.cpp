#include "pch.h"
#include "WarpShift.h"

WarpShift::WarpShift() :Cheat::Cheat("WarpShift", "Movement")
{

}

Vector3 savedPos;

void moveForward(LocalPlayer* Player) {
	Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.5f;
	Player->VelocityXYZ.y = (float)0;
	Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.5f;
}

bool distanceTooGreat(Vector3 savedPosVec, Vector3 currentPosVec) {
	float dX = savedPos.x - currentPosVec.x;
	float dZ = savedPos.z - currentPosVec.z;

	if (sqrt(dX * dX + dZ * dZ) >= (float)14) {
		return true;
	}
	else {
		return false;
	}
}

void WarpShift::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			if (KeyHook::KeyState(0x43)) {
				LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;

				if (distanceTooGreat(savedPos, *Player->getPos())) {
					Logger::log("Distance Too Great from original position!");
					Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * -1.4f;
					Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * -1.4f;
				}
				else {
					moveForward(Player);

					MovePlayerPacket* movementPacket = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 0x0);
					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movementPacket);

					delete movementPacket;
				}
			}
			else {
				savedPos = *LunMem::getClientInstance()->LocalPlayer->getPos();
			}
		}
	}
}

void WarpShift::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		if (KeyHook::KeyState(0x43)) {
			if (type == PacketType::Movement) {
				MovePlayerPacket* currentPacket = (MovePlayerPacket*)Packet;
				if (currentPacket->onGround == 0x1) {
					*cancel = true;
				}
			}
		}
	}
}

void WarpShift::onEnable()
{
	Cheat::onEnable();
	Logger::log("Hold 'C' to warp");
}