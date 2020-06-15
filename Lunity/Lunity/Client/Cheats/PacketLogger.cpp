#include "pch.h"
#include "PacketLogger.h"

PacketLogger::PacketLogger() : Cheat::Cheat("PacketLogger", "Other")
{

}

int packetId = 0;
void PacketLogger::onPacket(void* Packet, PacketType type, bool* cancel) {
	if (enabled) {
		Logger::logHex("Packet sent", (ulong)Packet);
		if (type == PacketType::Movement) {
			Logger::log("Packet was movement packet");
		}
		Logger::log("Saving packet to disk...");
		char logged[0x0110];
		memcpy(logged, Packet, 0x0110);
		string fileName = to_string(packetId) + string(".pkt");
		if (type != PacketType::Unknown) {
			if (type == PacketType::Movement) {
				fileName = string("Mvmt-") + fileName;
			}
			if (type == PacketType::Text) {
				fileName = string("Text-") + fileName;
			}
			if (type == PacketType::PlayerAuthInput) {
				fileName = string("PAIn-") + fileName;
			}
			if (type == PacketType::CraftingEvent) {
				fileName = string("Crft-") + fileName;
			}
		}
		string debugPath = string(getenv("APPDATA") + string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\Packets\\") + fileName);
		ofstream fout;
		fout.open(debugPath, ios::binary | ios::out);
		fout.write(logged, 0x0110);
		fout.close();
		Logger::log("Packet saved as "+ fileName);
		packetId++;
	}
}