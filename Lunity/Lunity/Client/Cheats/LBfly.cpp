#include "pch.h"
#include "LBfly.h"
#include "../Hooks/KeyHook.h"

float glidevar = 4.0f;
//how high will the player be tped

LBfly::LBfly() :Cheat::Cheat("LBfly", "Movement")
{

}

void LBfly::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
		if (Player != NULL) {
			Vector2 lookingVec = Player->LookingVec;
			if (KeyHook::KeyState(0x46)) {
				Player->VelocityXYZ.x = cos((lookingVec.y + 90.0f) * (3.14f / 180.0f)) * 0.4; //0.6 bypasses
				Player->VelocityXYZ.z = sin((lookingVec.y + 90.0f) * (3.14f / 180.0f)) * 0.4;
				Player->VelocityXYZ.y = 0;
			}
		}
	}
}

void LBfly::onPacket(void* Packet, PacketType type, bool* cancel)
{
	if (KeyHook::KeyState(0x46)) {
		if (enabled) {
			if (type == PacketType::Movement) {
				RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
				MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
				pkt->Pos.y += glidevar;
				glidevar -= 0.001f;
				//maybe can be even less idk (bigger value = faster downglide + less detectable)
			}
		}
	}
}