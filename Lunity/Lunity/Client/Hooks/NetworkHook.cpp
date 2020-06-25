#include "pch.h"
#include "NetworkHook.h"
#include "../../SDK/LunMem.h"
#include "../../SDK/LunMC.h"
#include "../../SDK/DrawUtils.h"
#include "../../Logger.h"
#include "../CheatManager.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")

typedef void (__thiscall* SendToServer)(LoopbackPacketSender* packetSender, void* Packet);
SendToServer original;

void __fastcall hookCallback(LoopbackPacketSender* packetSender, void* Packet) {
	PacketType pt = PacketType::Unknown;
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x31656B0) {
		pt = PacketType::Movement;
	}
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x3166940) {
		pt = PacketType::Text;
	}
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x31658B0) {
		pt = PacketType::PlayerAuthInput;
	}
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x3164960) {
		pt = PacketType::CraftingEvent;
	}
	if (*(ulong*)Packet == (ulong)GetModuleHandle(NULL) + 0x3164018) {
		pt = PacketType::ClientToServerHandshake;
	}
	bool canceled = false;
	CheatManager::onPacket(Packet, pt, &canceled);
	if (!canceled)
		original(packetSender, Packet);
}

void NetworkHook::installHook() {
	Logger::log("installing network hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0x10C7450);
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
	void* toHook = (void*)(LunMem::getBaseModule() + 0x10C7450);
	MH_DisableHook(toHook);
}
