#include "pch.h"
#include "NoPacket.h"

NoPacket::NoPacket() :Cheat::Cheat("NoPacket", "Other")
{

}

void NoPacket::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		*cancel = true;
	}
}