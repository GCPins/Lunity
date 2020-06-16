#include "pch.h"
#include "Criticals.h"

bool modifyPackets = true;

Criticals::Criticals() :Cheat::Cheat("Criticals", "Combat")
{
	registerToggleSetting("Modify Packets", &modifyPackets);
}

void Criticals::onEnable() {
	Cheat::onEnable();
	LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x102D926, (BYTE*)"\xB8\x00\x00\x00\x00\x90\x90", 7);
}

void Criticals::onDisable() {
	Cheat::onDisable();
	LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x102D926, (BYTE*)"\x0F\xB6\x86\x78\x01\x00\x00", 7);
}

void Criticals::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled && modifyPackets) {
		if (type == PacketType::Movement) {
			MovePlayerPacket* currentPacket = (MovePlayerPacket*)Packet;
			if (currentPacket->onGround == 0x1) {
				currentPacket->onGround = 0x0;
			}
		}
		else if (type == PacketType::PlayerAuthInput) {
			PlayerAuthInputPacket* currentPacket = (PlayerAuthInputPacket*)Packet;
			Vector3 currentPosition = *LunMem::getClientInstance()->LocalPlayer->getPos();
			if (currentPacket->Pos.y == currentPosition.y) currentPacket->Pos.y += (float)1.f;
		}
	}
}