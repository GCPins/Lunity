#include "pch.h"
#include "NetworkHook.h"
#include "../../SDK/LunMem.h"
#include "../../SDK/LunMC.h"
#include "../../SDK/DrawUtils.h"
#include "../../Logger.h"
#include "../CheatManager.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")

typedef int (__thiscall* SendToServer)(LoopbackPacketSender* packetSender, void* Packet);
SendToServer original;

int __fastcall hookCallback(LoopbackPacketSender* packetSender, void* Packet) {
	PacketType pt = Unknown;
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x2B04E68) {
		pt = Movement;
	}
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x2B05DB8) {
		pt = Text;
	}
	CheatManager::onPacket(Packet, pt);
	return original(packetSender, Packet);
}

void NetworkHook::installHook() {
	Logger::log("installing network hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0xFF0BE0);
	Logger::logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		Logger::log("Network Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			Logger::log("Network hook installed");
		}
	}
	if (!installSuccess) {
		Logger::log("Failed to hook network!");
	}
}

void NetworkHook::uninstallHook()
{
	void* toHook = (void*)(LunMem::getBaseModule() + 0xFF0BE0);
	MH_DisableHook(toHook);
}
