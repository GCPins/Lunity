#include "pch.h"
#include "CCFly.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"
#define PI 3.14159

CCFly::CCFly() : Cheat::Cheat("CCFly", "Movement")
{

}

float gliderar = 1.5f;
float leCCFlySpeed = .2f; //0.4 bypasses XD
bool ccmoving = false;
float addBy = 0;
int ticked = 0;
Vector3 lastPos;
int posSwitch;

float distance(Vector3* posA, Vector3* posB) {
	float dX = posA->x - posB->x;
	float dY = posA->y - posB->y;
	float dZ = posA->z - posB->z;
	float dist = sqrt(dX * dX + dY * dY + dZ * dZ);
	return dist;
}

void CCFly::onEnable() {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			lastPos = *Player->getPos();
		}
	}
}

void CCFly::onGmTick(GameMode* gm)
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			if (KeyHook::KeyState(0x46)) {
				if (!ccmoving) {
					ccmoving = true;
					addBy = 0;
					//ticked = 0;
					lastPos = *Player->getPos();
					//Player->jumpFromGround();
					//Player->actuallyHurt(1, (Actor*)Player, false);
					//Player->animateHurt();
					Player->swing();

					//MovePlayerPacket* pkt = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 1);
					//pkt->Pos.x += cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					//pkt->Pos.y += (float)0;
					//pkt->Pos.z += sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(pkt);
					//delete pkt;


					Player->swing();

					//Player->startSwimming();

					Logger::log("Moving!");
					ticked = 0;
				}
				if (ccmoving) {
					Player->setSprinting(true);
					//Move the player client
					Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
					Player->VelocityXYZ.y = 0.0f;
					Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
						if (ticked == 40) { ticked = 0; }
					ticked++;
				}
			}
			else {
				if (ccmoving) {
					ccmoving = false;
					Player->VelocityXYZ.x = (float)0;
					Player->VelocityXYZ.y = (float)0;
					Player->VelocityXYZ.z = (float)0;
					//Player->stopSwimming();
					Logger::log("Stop Moving!");
				}
			}
		}
	}
}

void CCFly::onPacket(void* Packet, PacketType type, bool* cancel)
{
	if (enabled) {
		if (ccmoving) {
			if (type == PacketType::Movement) {
				if (LunMem::getClientInstance() != NULL) {
					LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
					if (Player != NULL) {
						RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
						MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
						pkt->Pos.y += gliderar;
						if (ticked >= 20)
						{
							pkt->Pos.y -= 0.5f;
						}
						else
						{
							pkt->Pos.y += 0.5f;
						}
						gliderar -= 0.001f;
						if (gliderar < 0.5) { gliderar = 1.5f; }
					}
				}
			}
		}
	}
}