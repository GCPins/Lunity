#pragma once
#include "../BigHead.h"
#include <polyhook2/Detour/x64Detour.hpp>
#include <polyhook2/CapstoneDisassembler.hpp>
#pragma comment(lib, "PolyHook_2.lib")
//#pragma comment(lib, "PolyHook/capstone_dll.lib")

ulong keyPressTramp = NULL;
ulong hooker = LunMem::getBaseModule() + 0xD549F0;
void onKeyPress(ulong uParm1, ulong* uParm2) {
	log("Key press hook!");
	logHex("Param1", uParm1);
	logHex("Param2", (ulong)uParm2);
	void(*func)(ulong a, ulong * b);
	func = (void(*)(ulong a, ulong * b))hooker;
	return PLH::FnCast(keyPressTramp, func)(uParm1, uParm2);
}
void installHooks() {
	log("Hooking key shit...");
	hooker = LunMem::getBaseModule() + 0xD549F0;
	logHex("Hook addr:", hooker);
	PLH::CapstoneDisassembler dis(PLH::Mode::x64);
	PLH::x64Detour detour((const char*)hooker, (const char*)onKeyPress, &keyPressTramp, dis);
	detour.hook();
	log("Detoured!");
	return;
}

