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
			Player->VelocityXYZ.y = (float)0;

			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(250)) {

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