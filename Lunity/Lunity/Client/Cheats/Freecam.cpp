#include "pch.h"
#include "Freecam.h"

Vector3 savedPlayerPos;

Freecam::Freecam() :Cheat::Cheat("Freecam", "Other")
{
	
}

void Freecam::onEnable()
{
	Cheat::onEnable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			savedPlayerPos = *LunMem::getClientInstance()->LocalPlayer->getPos();
		}
	}
}

void Freecam::onDisable() {
	Cheat::onDisable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			 LunMem::getClientInstance()->LocalPlayer->setPos(&savedPlayerPos);
		}
	}
}

void Freecam::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		if (type == PacketType::Movement) {
			if (LunMem::getClientInstance() != NULL) {
				if (LunMem::getClientInstance()->LocalPlayer != NULL) {
					*cancel = true;
				}
			}
		}
	}
}