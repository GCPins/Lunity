#include "pch.h"
#include "CCGodMode.h"
//#include "Speed.h"
//#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"

//float spyeet = 0.2f;
float aaabbb = 4.0f;

CCGodMode::CCGodMode() : Cheat::Cheat("CCGodMode", "Other")
{
}

float distancx;
float distancz;

Vector2 RunAngles;

void CCGodMode::onPacket(void* Packet, PacketType type, bool* cancel)
{
	if (enabled) {
		if (type == PacketType::Movement) {
			/*		if (type == PacketType::Movement) {
						MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
						pkt->Pos.y += 8;
						//Vector3 myPosition = *LunMem::getClientInstance()->LocalPlayer->getPos();
						//pkt->Pos.x = myPosition.x;
						//pkt->Pos.z = myPosition.z; //to fix the lagbacks, doesnt work
					}
				}
			*/
			RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			vector<Actor*>* ents = getEntities();
			for (uint i = 0; i < ents->size(); i++) {
				if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= 3.5f) {
					//do stuff
					MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
					pkt->Pos.y += aaabbb;
					aaabbb -= 0.001f;

					pkt->Pos.x = (ents->at(i)->getPos()->x);
					
					pkt->Pos.z = (ents->at(i)->getPos()->z);
					
				}
				else
				{
					aaabbb = 4.0f;
				}
			}
		}
	}
}