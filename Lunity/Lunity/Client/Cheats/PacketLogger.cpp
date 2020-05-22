#include "pch.h"
#include "PacketLogger.h"

PacketLogger::PacketLogger() : Cheat::Cheat("PacketLogger", "Other")
{
}

void PacketLogger::onEnable()
{
	/*
	LunMem::getClientInstance()->LocalPlayer->displayLocalizableMessage(new TextHolder("Test!"));
	LunMem::getClientInstance()->LocalPlayer->setName(new TextHolder("Franklin"));
	LunMem::getClientInstance()->LocalPlayer->setNameTagVisible(true);
	*/
	//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(new TextHolder(string("Hello!")));
	//enabled = false;
}

void PacketLogger::onTick() {
	
}

void PacketLogger::onGmTick(GameMode* gm) {

}

void PacketLogger::onPacket(void* Packet, PacketType type) {
	if (enabled) {
		Logger::logHex("Packet sent", (ulong)Packet);
		if (type == Movement) {
			Logger::log("Packet was movement packet");
		}
		if (type == Text) {
			Logger::log("Packet was text packet");
			while(1){}
		}
	}
}