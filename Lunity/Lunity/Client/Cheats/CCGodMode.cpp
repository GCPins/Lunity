#include "pch.h"
#include "CCGodMode.h"

CCGodMode::CCGodMode() : Cheat::Cheat("CCGodMode", "Other")
{
}

void CCGodMode::onPacket(void* Packet, PacketType type, bool* cancel)
{
	if (enabled) {
		if (type == PacketType::Movement) {
			MovePlayerPacket* pkt = (MovePlayerPacket*)Packet;
			pkt->Pos.y += 8;
		}
	}
}
