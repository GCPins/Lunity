#include "pch.h"
#include "KeyHook.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")
#include "../../BigHead.h"
#include "../CheatManager.h"
#include <map>

typedef int (WINAPI* KeyPressed)(ulong key, bool pressed);
KeyPressed original;

void KeyHook::installHook() {
	Logger::log("installing hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0xE28090);
	Logger::logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		Logger::log("Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			Logger::log("key hook installed");
		}
	}
	if (!installSuccess) {
		Logger::log("Failed to hook!");
	}
}

void KeyHook::uninstallHook()
{
	void* toHook = (void*)(LunMem::getBaseModule() + 0xE28090);
	MH_DisableHook(toHook);
}

std::map<ulong, bool> keyState;

void KeyHook::KeyPressed(ulong key) {
	keyState[key] = true;
	CheatManager::distroKeyPress(key);
}

void KeyHook::KeyReleased(ulong key) {
	keyState[key] = false;
	//log("Release");
}

bool KeyHook::KeyState(ulong key) {
	return keyState[key];
}

int KeyHook::hookCallback(ulong key, bool pressed) {
	//log(std::string(1, key));
	if (pressed) {
		KeyPressed(key);
	}
	else {
		KeyReleased(key);
	}
	//distroKey(key);
	return original(key, pressed);
}