#include "pch.h"
#include "CCFly.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"
#define PI 3.14159

float leCCFlySpeed = 0.25f;

float yee = 1.5f;

CCFly::CCFly():Cheat::Cheat("CCFly", "Movement")
{
	registerSliderSetting("Speeeeet", &leCCFlySpeed, 0.0f, 2.0f);
	registerSliderSetting("yee", &yee, 0.0f, 8.0f);
}

float gliderar;
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

					lastPos = *Player->getPos();

					Player->swing();

					Logger::log("Moving!");
					ticked = 0;
					gliderar = yee;
				}
				if (ccmoving) {
					Player->setSprinting(true);
					//Move the player client
					Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
					Player->VelocityXYZ.y = 0.0f;
					Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
						if (ticked == 40) { ticked = 0; }
					ticked++;
					if (yee < 0.6f)
					{
						yee = 0.6;
					}
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
						if (ticked <= 15)
						{
							pkt->Pos.y += 0.5f;
						}
						else
						{
							if (ticked >= 25)
							{
								pkt->Pos.y -= 0.5f;
							}
							else
							{
								*cancel = true;
							}
						}
						gliderar -= 0.001f;
						if (gliderar <= 0.5) 
						{ 
							gliderar = (float)yee; 
						}
						//Logger::log(to_string(gliderar)); debug meh idk
					}
				}
			}
		}
	}
}