#pragma once
#define ulong uint64_t
#include <Windows.h>
#include "Player.h"
#include "Logger.h"

static HMODULE gameBase;
static Player localPlayer=NULL;
static void initSDK() {
	gameBase = GetModuleHandle(NULL);
	//log("Got handle!" + std::to_string((ulong)gameBase));
    ulong offsets[] = { 0xA8, 0x58, 0x38, 0x8, 0x0 };
	localPlayer = (ulong*)evaluatePointer((ulong)gameBase + 0x02FFAF50, offsets);
    log("Got local player!" + std::to_string((ulong)localPlayer.address));
}

static void updateSDK() {
    ulong offsets[] = { 0xA8, 0x58, 0x38, 0x8, 0x0 };
    localPlayer.address = (ulong*)evaluatePointer((ulong)gameBase + 0x02FFAF50, offsets);
    log("Got local player!" + (ulong)localPlayer.address);
}