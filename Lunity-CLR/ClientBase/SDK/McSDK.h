#pragma once
#define ulong uint64_t
#include <Windows.h>
#include "Player.h"
#include "Logger.h"

static HMODULE gameBase;
static Player localPlayer=NULL;
static void initSDK() {
	gameBase = GetModuleHandle(NULL);
	log("Got handle!" + std::to_string((ulong)gameBase));
	localPlayer = Player((ulong*)(*(ulong*)(*(ulong*)(*(ulong*)(gameBase + 0x02FFAF50)+0xA8)+0x58)+0x38)+0x8);
}