#include "pch.h"
#include "KeyHook.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")
#include "../BigHead.h"

typedef int (WINAPI* KeyPressed)(void*, void*);
KeyPressed original;

void KeyHook::installHook() {
	log("installing hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0xD549F0);
	logHex("ToHook: ", (ulong)toHook);
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

int KeyHook::hookCallback(void* keycodePtr, void* keycodeItem) {
	log("Callback!");
	return original(keycodePtr, keycodeItem);
}