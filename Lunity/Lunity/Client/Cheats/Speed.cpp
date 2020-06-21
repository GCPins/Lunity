#include "pch.h"
#include "Speed.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float speedValue = 0.24f;
float lowhopseepdValue = 0.12f;
float vhopseepdValue = 1.0f;
float vhopheightValue = 1.0f;

bool vanilla = true;
bool lowhop = false;
bool vhop = false;
bool bypass = false;
bool sprint = false;

//vhop
Vector3 beforejumppos;
Vector3 jumppos;
float heightdiff = 0.0f;
bool vhopfall = false;

//cc
float ypos = 0.5;

Speed::Speed() :Cheat::Cheat("Speed", "Movement")
{
	registerToggleSetting("Vanilla", &vanilla);
	registerToggleSetting("Lowhop", &lowhop);
	registerToggleSetting("Vhop", &vhop);
	registerToggleSetting("Bypass", &bypass);
	registerToggleSetting("Sprint", &sprint);
	registerSliderSetting("Speed", &speedValue, 0.0f, 2.0f);
	registerSliderSetting("Lowhop speed", &lowhopseepdValue, 0.0f, 2.0f);
	registerSliderSetting("Vhop speed", &vhopseepdValue, 0.0f, 2.0f);
	registerSliderSetting("Vhop height", &vhopheightValue, 0.0f, 2.0f);
}

void Speed::onGmTick(GameMode* gm)
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			if (vanilla) {
				float calcYaw = Player->LookingVec.y;

				bool pressedWKey = KeyHook::KeyState(0x57);
				bool pressedSKey = KeyHook::KeyState(0x53);
				bool pressedAKey = KeyHook::KeyState(0x41);
				bool pressedDKey = KeyHook::KeyState(0x44);

				if (pressedWKey) {
					if (!pressedAKey && !pressedDKey) {
						calcYaw += 90.0f;
					}
					else if (pressedAKey) {
						calcYaw += 45.0f;
					}
					else if (pressedDKey) {
						calcYaw += 135.0f;
					}
				}
				else if (pressedSKey) {
					if (!pressedAKey && !pressedDKey) {
						calcYaw -= 90.0f;
					}
					else if (pressedAKey) {
						calcYaw -= 45.0f;
					}
					else if (pressedDKey) {
						calcYaw -= 135.0f;
					}
				}
				else if (!pressedWKey && !pressedSKey) {
					if (pressedDKey) {
						calcYaw += 180.0f;
					}
				}

				if (pressedWKey | pressedSKey | pressedAKey | pressedDKey) {
					Player->VelocityXYZ.x = cos((calcYaw) * (PI / 180.0f)) * speedValue;
					Player->VelocityXYZ.z = sin((calcYaw) * (PI / 180.0f)) * speedValue;
				}
			}
			if (lowhop) {
				if (Player->OnGround)
				{
					Player->jumpFromGround();
					vhopfall = false;
				}
				else
				{
					Player->VelocityXYZ.y = lowhopseepdValue * -1 - 0.01f;
				}
			}
			if (Player->OnGround & vhop)
			{
				beforejumppos = *Player->getPos();
				Player->jumpFromGround();
				vhopfall = false;
			}
			if (!Player->OnGround && vhop)
			{
				jumppos = *Player->getPos();

				heightdiff = jumppos.y - beforejumppos.y;
				if (heightdiff > vhopheightValue)
				{
					vhopfall = true;
				}

				if (vhopfall)
				{
					Player->VelocityXYZ.y = vhopseepdValue *-1 - 0.01f;
				}
				else
				{
					Player->VelocityXYZ.y = vhopseepdValue + 0.01f;
				}
			}
			if (sprint)
			{
				Player->setSprinting(true);
			}
		}
	}
}

void Speed::onPacket(void* Packet, PacketType type, bool* cancel)
{
	if (enabled) {
		if (bypass) {
			if (type == PacketType::Movement) {
				if (LunMem::getClientInstance() != NULL) {
					LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
					if (Player != NULL) {
						RakNetInstance* Raknet = LunMem::getClientInstance()->LoopbackPacketSender->NetworkHandler->RakNetInstance;
						MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
						pkt->Pos.y += ypos;
							if (ypos <= 0.1)
							{
								ypos = 0.5f;
							}
						ypos -= 0.001f;
					}
				}
			}
		}
	}
}