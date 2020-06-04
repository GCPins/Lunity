#include "pch.h"
#include "HiveGlide.h"

/*
0x900617
(BYTE*)"\xFF\x50\x08"
*/

static std::chrono::time_point<std::chrono::steady_clock> savedTime;
bool toggle = false;

HiveGlide::HiveGlide() :Cheat::Cheat("HiveGlide", "Movement")
{

}

void HiveGlide::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			
			if (KeyHook::KeyState(0x57)) {
				Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.3f;
				Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.3f;
			}

			Player->VelocityXYZ.y = (float)0;

			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(200)) {

				if (toggle) {
					toggle = false;
				}
				else {
					toggle = true;
				}

				savedTime = std::chrono::high_resolution_clock::now();
			}
		}
	}
}

void HiveGlide::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		if (type == PacketType::Movement) {
			if (toggle) *cancel = true;
		}
	}
}

void HiveGlide::onEnable()
{
	Cheat::onEnable();
	Logger::log("Made by the help of R3coil");
	savedTime = std::chrono::high_resolution_clock::now();
}

void HiveGlide::onDisable() {
	Cheat::onDisable();
	toggle = false;
}