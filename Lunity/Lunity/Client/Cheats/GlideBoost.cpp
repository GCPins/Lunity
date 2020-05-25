#include "pch.h"
#include "GlideBoost.h"

#define PI 3.14159

float glideBoostSpeed = 1.2;
bool moving = false;
Vector3 savedPos;
Vector2 lookingVec;

GlideBoost::GlideBoost() :Cheat::Cheat("GlideBoost", "Movement")
{

}

void GlideBoost::onEnable()
{
	Cheat::onEnable();
}

void GlideBoost::onDisable()
{
	Cheat::onDisable();
}

void GlideBoost::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			if (KeyHook::KeyState(0x47)) {
				if (!moving) {
					savedPos = *Player->getPos();
					lookingVec = Player->LookingVec;
					Logger::log("Moving!");
					moving = true;
				}
				if (moving) {

					LunMem::Nop((BYTE*)LunMem::getBaseModule() + 0x900617, 3);

					Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * glideBoostSpeed;
					Player->VelocityXYZ.y = (float)0;
					Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * glideBoostSpeed;

					MovePlayerPacket* movementPacket = new MovePlayerPacket((Actor*)Player, &savedPos, &lookingVec, 0x1);
					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movementPacket);
				}
			}
			else {
				if (moving) {
					LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x900617, (BYTE*)"\xFF\x50\x08", 3);
					moving = false;
					Logger::log("No Longer Moving!");
				}
			}
		}
	}
}