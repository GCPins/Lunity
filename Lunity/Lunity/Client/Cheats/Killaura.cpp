#include "pch.h"
#include "Killaura.h"
#include "../Hooks/GamemodeHook.h"
#include "../../SDK/EntList.h"
#include "../../SDK/LunMath.h"

static std::chrono::time_point<std::chrono::steady_clock> savedTime;
float killauraDelayF = 0.f;
bool multiEnts = true;
bool changeCamera = true;
float rangeeee = 12.0f;

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{
	registerSliderSetting("Delay (MS)", &killauraDelayF, 0.f, 1000.f);
	registerSliderSetting("Range", &rangeeee, 0.f, 50.f);
	registerToggleSetting("Multiple Entities", &multiEnts);
	registerToggleSetting("Face Entity", &changeCamera);
}

Vector2 lookingAngles;

void Killaura::onGmTick(GameMode* gm) {
	RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	vector<Actor*>* ents = getEntities();
	vector<double> rangesArr;
	if (ents != NULL) {
		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds((int)killauraDelayF)) {
			if (multiEnts) {
				for (uint i = 0; i < ents->size(); i++) {
					if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= rangeeee) {
						lookingAngles = LunMath::getRotationAnglesToEnt(*ents->at(i)->getPos(), *player->getPos());
						player->swing();
						gm->attack(ents->at(i));
					}
				}
			}
			else {
				for (uint i = 0; i < ents->size(); i++) {
					float distance = LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos());
					if (distance <= rangeeee) {
						rangesArr.push_back(distance);
					}
				}

				if (rangesArr.size() > 0) {
					std::sort(rangesArr.begin(), rangesArr.end());

					for (uint I = 0; I < ents->size(); I++) {
						if (LunMath::distanceVec3(*ents->at(I)->getPos(), *player->getPos()) == rangesArr[0]) {
							player->swing();
							gm->attack(ents->at(I));
							break;
						}
					}
				}
			}

			savedTime = std::chrono::high_resolution_clock::now();
		}
	}
}

void Killaura::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled && changeCamera) {
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