#include "pch.h"
#include "WarpShift.h"

WarpShift::WarpShift() :Cheat::Cheat("WarpShift", "Movement")
{

}

void moveForward(LocalPlayer* Player) {
	Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.6f;
	Player->VelocityXYZ.y = (float)0;
	Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.6f;
}

void WarpShift::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			if (KeyHook::KeyState(0x43)) {
				LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;

				moveForward(Player);

				MovePlayerPacket* movementPacket = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 0x0);
				LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movementPacket);

				delete movementPacket;
			}
		}
	}
}

void WarpShift::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		if (KeyHook::KeyState(0x43)) {
			if (type == PacketType::Movement) {
				MovePlayerPacket* currentPacket = (MovePlayerPacket*)Packet;
				if (currentPacket->onGround == 0x0) {
					*cancel = false;
				}
				else {
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