#include "pch.h"
#include "KeyHook.h"

uint64_t keyPressTramp = NULL;
void onKeyPress(ulong uParm1, ulong* uParm2) {

}

KeyHook::KeyHook() {
	PLH::CapstoneDisassembler dis(PLH::Mode::x64);
	uint64_t hooker = LunMem::getBaseModule() + 0xD549F0;
	PLH::x64Detour detour(hooker, onKeyPress, &keyPressTramp, dis);
	detour.hook();
	return;
}