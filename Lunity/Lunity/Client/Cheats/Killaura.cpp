#include "pch.h"
#include "Killaura.h"
#include "../Hooks/GamemodeHook.h"
#include "../../SDK/EntList.h"
#include "../../SDK/LunMath.h"

static std::chrono::time_point<std::chrono::steady_clock> savedTime;

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{

}

Vector2 lookingAngles;

void Killaura::onGmTick(GameMode* gm) {
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	vector<Actor*>* ents = getEntities();
	if (ents != NULL) {
		RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
		if (strcmp(Raknet->ServerIp.getText(), "mco.cubecraft.net") == 0) {
			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(200)) {
				for (uint i = 0; i < ents->size(); i++) {
					if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= 12.0f) {
						lookingAngles = LunMath::getRotationAnglesToEnt(*ents->at(i)->getPos(), *player->getPos());
						player->swing();
						gm->attack(ents->at(i));
					}
				}
				savedTime = std::chrono::high_resolution_clock::now();
			}
		}
		else {
			for (uint i = 0; i < ents->size(); i++) {
				if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= 12.0f) {
					lookingAngles = LunMath::getRotationAnglesToEnt(*ents->at(i)->getPos(), *player->getPos());
					player->swing();
					gm->attack(ents->at(i));
				}
			}
		}
	}
}

void Killaura::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		if (lookingAngles.x != (float)0.f && lookingAngles.y != (float)0.f) {
			if (type == PacketType::Movement) {
				MovePlayerPacket* currentPacket = (MovePlayerPacket*)Packet;
				currentPacket->LookingVec = lookingAngles;
				lookingAngles.x = (float)0.f;
				lookingAngles.y = (float)0.f;
			}
			else if (type == PacketType::PlayerAuthInput) {
				PlayerAuthInputPacket* currentPacket = (PlayerAuthInputPacket*)Packet;
				currentPacket->LookingVec = lookingAngles;
				lookingAngles.x = (float)0.f;
				lookingAngles.y = (float)0.f;
			}
		}
	}
}