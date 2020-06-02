#include "pch.h"
#include "GlideBoost.h"

#define PI 3.14159

//float glideBoostSpeed = .4;
//bool moving = false;
//Vector3* savedPos;
//Vector2 lookingVec;

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

int sentCount = 0;
void GlideBoost::onPacket(void* Packet, PacketType type, bool* cancel) {
	/*if (enabled) {
		if (moving) {
			RakNetInstance* rak = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
			if (strcmp(rak->ServerIp.getText(), "mco.cubecraft.net") == 0) {
				if (type == PacketType::Movement || type == PacketType::PlayerAuthInput) {
					if (sentCount % 70) {
						*cancel = true;
						Logger::log("Canceled packet to cc!");
					}
					else {
						Logger::log("Sent packet to cc!");
					}
					sentCount++;
				}
			}
		}
	}*/
}

//float distance(Vector3* posA, Vector3* posB) {
//	float dX = posA->x - posB->x;
//	float dY = posA->y - posB->y;
//	float dZ = posA->z - posB->z;
//	float dist = sqrt(dX * dX + dY * dY + dZ * dZ);
//	return dist;
//}

//Vector3 Nofavec;
//Vector3* lastPos;
//float incYBy = 0;
//bool leSwitch = false;
void GlideBoost::onTick()
{
	//Cheat::onTick();
	//if (LunMem::getClientInstance() != NULL) {
	//	if (LunMem::getClientInstance()->LocalPlayer != NULL) {
	//		RakNetInstance* rak = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
	//		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	//		if (KeyHook::KeyState(0x47)) {
	//			if (!moving) {
	//				savedPos = Player->getPos();
	//				lookingVec = Player->LookingVec;
	//				Logger::log("Moving!");
	//				moving = true;
	//				Vector3* pos = Player->getPos();
	//				lastPos = new Vector3{ pos->x, pos->y, pos->z };
	//				incYBy = 0;
	//			}
	//			if (moving) {

	//				//LunMem::Nop((BYTE*)LunMem::getBaseModule() + 0x900617, 3);

	//				Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * glideBoostSpeed;
	//				Player->VelocityXYZ.y = (float)0;
	//				Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * glideBoostSpeed;

	//				if (strcmp(rak->ServerIp.getText(), "geo.hivebedrock.network") == 0) {
	//					MovePlayerPacket* a = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 0x1);
	//					a->Pos.y = savedPos->y - 9;
	//					LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(a);
	//				}
	//				if (strcmp(rak->ServerIp.getText(), "mco.cubecraft.net") == 0) {
	//					Vector3* pos = Player->getPos();
	//					float dist = distance(lastPos, pos);
	//					if (dist >= 1) {
	//						if (leSwitch) {
	//							Vector2 lookingVec = Player->LookingVec;
	//							Vector3* currentPos = Player->getPos();
	//							float nx = currentPos->x + cos((lookingVec.y + 90.0f) * (PI / 180.0f)) * 1;
	//							float ny = currentPos->y + sin((lookingVec.x) * -(PI / 180.0f)) * 1;
	//							float nz = currentPos->z + sin((lookingVec.y + 90.0f) * (PI / 180.0f)) * 1;
	//							//Logger::log(to_string(nx));
	//							Vector3* newPos = new Vector3();
	//							newPos->x = nx;
	//							newPos->y = ny;
	//							newPos->z = nz;
	//							Player->setPos(newPos);
	//							leSwitch = false;
	//						}
	//						else {
	//							leSwitch = true;
	//						}
	//						MovePlayerPacket* a = new MovePlayerPacket((Actor*)Player, Player->getPos(), &Player->LookingVec, 0x1);
	//						a->Pos.y += incYBy;
	//						LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(a);
	//						delete a;
	//						Logger::log("Sent packet to cc!");
	//						lastPos = new Vector3{ pos->x, pos->y, pos->z };
	//						incYBy += .3;
	//					}
	//				}
	//				
	//			}
	//		}
	//		else {
	//			if (moving) {
	//				//LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x900617, (BYTE*)"\xFF\x50\x08", 3);
	//				moving = false;
	//				Player->VelocityXYZ.x = (float)0;
	//				Player->VelocityXYZ.y = (float)0;
	//				Player->VelocityXYZ.z = (float)0;
	//				Logger::log("No Longer Moving!");
	//			}
	//		}
	//	}
	//}
}