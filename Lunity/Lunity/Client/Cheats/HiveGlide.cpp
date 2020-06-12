#include "pch.h"
#include "HiveGlide.h"

/*
0x900617
(BYTE*)"\xFF\x50\x08"
*/

static std::chrono::time_point<std::chrono::steady_clock> savedTime;
bool toggle = false;
//bool onlyPrintOnce = false;

HiveGlide::HiveGlide() :Cheat::Cheat("HiveGlide", "Movement")
{

}

void HiveGlide::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
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
				Player->VelocityXYZ.x = cos((calcYaw) * (3.14159 / 180.0f)) * 0.3f;
				Player->VelocityXYZ.y = (float)0;
				Player->VelocityXYZ.z = sin((calcYaw) * (3.14159 / 180.0f)) * 0.3f;
			}

			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(150)) {

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
	/*Cheat::onEnable();
	if (!onlyPrintOnce) {
		Logger::log("Made by the help of R3coil");
		onlyPrintOnce = true;
	}
	savedTime = std::chrono::high_resolution_clock::now();
	*/
}

void HiveGlide::onDisable() {
	Cheat::onDisable();
	toggle = false;
}