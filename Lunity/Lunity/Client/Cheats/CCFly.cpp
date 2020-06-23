#include "pch.h"
#include "CCFly.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"
#define PI 3.14159

static std::chrono::time_point<std::chrono::steady_clock> savedTime;

float leCCFlySpeed = 0.25f;

float yee = 1.5f;

bool pulse = false;

//float pulseinterval = 0.25;

int Eeeeeee = 1;

float boithesevariablesrbest = 0.001;

//bool bump = false;

//float aaaaaaaaaaaaaaaaa = 0.0f;

CCFly::CCFly() :Cheat::Cheat("CCFly", "Movement")
{
	registerSliderSetting("Speed", &leCCFlySpeed, 0.0f, 2.0f);//speed
	registerSliderSetting("yee", &yee, 0.0f, 8.0f);//how high will it tp u
	registerSliderSetting("Glide", &boithesevariablesrbest, 0.001f, 0.5f);//"glide speed"
	//registerToggleSetting("Bump", &bump);//more like airjump
	//registerSliderSetting("Bump", &aaaaaaaaaaaaaaaaa, 0.0f, 2.0f);//bump valocity
	registerToggleSetting("Pulse", &pulse);//fly with the speed only 500ms else use speed/2
}

float gliderar;
bool ccmoving = false;
float addBy = 0;
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

void CCFly::onTick() {
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(50));
	{
		Eeeeeee++;
			if (Eeeeeee > 30) //Eeeeeee > 3
			{
				Eeeeeee = 1;
			}
		savedTime = std::chrono::high_resolution_clock::now();
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
					gliderar = yee;
				}
				if (ccmoving) {
					Player->setSprinting(true);
					//Move the player client
					if (pulse)
					{
						if (Eeeeeee > 20)
						{
							Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
							Player->VelocityXYZ.y = 0.0f;
							Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
						}
						else
						{
							Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * (leCCFlySpeed / 2.0f);
							Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * (leCCFlySpeed / 2.0f);
						}
					}
					else
					{
						Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
						Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90) * (PI / 180.0f)) * leCCFlySpeed;
					}
					if (yee < 0.6f)
					{
						yee = 0.6;
					}
						Player->VelocityXYZ.y = 0.0f;
					/*if (!glide & bump)
					{
						if (Eeeeeee == 1)
						{
							Player->VelocityXYZ.y = aaaaaaaaaaaaaaaaa;
						}
					}*/
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
						if (KeyHook::KeyState(0x46)) {
							pkt->Pos.y += gliderar;
							if (Eeeeeee < 10)
							{
								pkt->Pos.y += 0.5f;
							}
							if (Eeeeeee > 10 & Eeeeeee < 20)
							{
								pkt->Pos.y -= 0.5f;
							}
							if (Eeeeeee > 20 & Eeeeeee < 30)
							{
								*cancel = true;
							}
							gliderar -= boithesevariablesrbest;
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
}