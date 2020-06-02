#include "pch.h"
#include "CCFly.h"
#include "../Hooks/KeyHook.h"
#define PI 3.14159
CCFly::CCFly() : Cheat::Cheat("CCFly", "Movement")
{
}
float leCCFlySpeed = .3f;
bool ccmoving = false;
float addBy = 0;
int ticked = 0;
Vector3 Nofavec;
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
					Player->jumpFromGround();
					Logger::log("Moving!");
				}
				if (ccmoving) {
					////Lucy's disabler (outdated, same as flare those scumbags)
					//Vector3* posa = Player->getPos();
					//Vector3* bedPos = new Vector3{ posa->x, posa->y - 1.6f, posa->z };
					//Vector3* pos = Player->getPos();
					//Nofavec = *pos;
					//Nofavec.y += 1.6;
					//MovePlayerPacket* a = new MovePlayerPacket((Actor*)Player, &Nofavec, &Player->LookingVec, 0x0);
					//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(a);
					//delete a;
					//Nofavec.y -= 1.6;
					//MovePlayerPacket* a2 = new MovePlayerPacket((Actor*)Player, &Nofavec, &Player->LookingVec, 0x0);
					//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(a2);
					//delete a2;

					////Part 2
					//Vector3* posb = Player->getPos();
					//Vector3* copyPosb = new Vector3{ posb->x, posb->y, posb->z };
					//MovePlayerPacket* movePlayerPacket = new MovePlayerPacket((Actor*)Player, copyPosb, &Player->LookingVec, 0x0);
					//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movePlayerPacket);
					//delete movePlayerPacket;
					//copyPosb->y = -4477558.0f;
					//movePlayerPacket = new MovePlayerPacket((Actor*)Player, copyPosb, &Player->LookingVec, 0x0);
					//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movePlayerPacket);
					//delete movePlayerPacket;

					MovePlayerPacket* movePlayerPacket = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 0x1);
					movePlayerPacket->Pos.y = Player->getPos()->y + addBy;
					Logger::log(to_string(movePlayerPacket->Pos.y));
					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(movePlayerPacket);

					if (ticked % 7 == 0) {
						addBy += 1;
					}
					ticked++;


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
					Logger::log("Stop Moving!");
				}
			}
		}
	}
}

void CCFly::onPacket(void* Packet, PacketType type, bool* cancel)
{
	/*if (ccmoving) {
		if (type == PacketType::Movement || type == PacketType::PlayerAuthInput) {
			if (sent % 4 != 0) {
				*cancel = true;
			}
			else {
				MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
				pkt->Pos.y -= subBy;
				subBy -= 0.1f;
				Logger::log("Sent to CC");
			}
			sent++;
		}
	}*/
}
