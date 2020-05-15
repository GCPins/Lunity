#include "pch.h"
#include "KeyHook.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")
#include "../BigHead.h"
#include "CheatManager.h"
#include <map>

typedef int (WINAPI* KeyPressed)(ulong key, bool pressed);
KeyPressed original;

void KeyHook::installHook() {
	log("installing hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0xD549F0);
	logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		log("Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			log("key hook installed");
		}
	}
	if (!installSuccess) {
		log("Failed to hook!");
	}
}

std::map<ulong, bool> keyState;

void KeyHook::KeyPressed(ulong key) {
	keyState[key] = true;
	CheatManager::distroKeyPress(key);
	log("Press");
}

void KeyHook::KeyReleased(ulong key) {
	keyState[key] = false;
	log("Release");
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