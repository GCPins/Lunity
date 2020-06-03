#include "pch.h"
#include "CCFly.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"
#define PI 3.14159
CCFly::CCFly() : Cheat::Cheat("CCFly", "Movement")
{
}
float leCCFlySpeed = .2f;
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
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	lastPos = *Player->getPos();
	//Player->getPos()->y += 5;
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
					ticked = 0;
					lastPos = *Player->getPos();
					//Player->jumpFromGround();
					//Player->actuallyHurt(1, (Actor*)Player, false);
					//Player->animateHurt();
					Player->swing();

					MovePlayerPacket* pkt = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 1);
					pkt->Pos.x += cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					pkt->Pos.y += (float)0;
					pkt->Pos.z += sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(pkt);
					delete pkt;

					Player->swing();

					//Player->startSwimming();

					//Player->getPos()->y += 5;
					Logger::log("Moving!");
				}
				if (ccmoving) {
					MovePlayerPacket* pkt = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 1);
					pkt->Pos.x += cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					pkt->Pos.y += (float)0;
					pkt->Pos.z += sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * 5;
					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(pkt);
					delete pkt;

					//Move the player client
					Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
					Player->VelocityXYZ.y = (float)0;
					Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
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
	//if (enabled) {
	//	if (type == PacketType::Movement || type == PacketType::PlayerAuthInput) {
	//		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	//		MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
	//		pkt->onGround = true;
	//		/*if (ticked % 3 == 0) {
	//			addBy += 1.0f;
	//		}
	//		ticked++;*/
	//		//Logger::log("Sent to CC");
	//	}
	//}
}
