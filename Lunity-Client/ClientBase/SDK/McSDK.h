#pragma once
#define ulong uint64_t
#include <Windows.h>
#include "Player.h"
#include "Logger.h"
#include <vector>

template<size_t X>
ulong evaluatePointer(ulong addr, ulong (&offsets)[X])
{
    //log("Dereffing... 0-> " + std::to_string(addr));
    ulong buffer = *(ulong*)addr;
    if (buffer == 0) {
        return 0;
    }
    //log("Dereffed base: " + std::to_string(buffer));
    for (int i = 0; i < X - 1; i++)
    {
        buffer = *(ulong*)(buffer + offsets[i]);
        //log("Dereffed "+ std::to_string(i)+": " + std::to_string(buffer));
    }
    return buffer + offsets[X - 1];
}

static HMODULE gameBase;
static Player localPlayer = NULL;
static void initSDK() {
	gameBase = GetModuleHandle(NULL);
	//log("Got handle!" + std::to_string((ulong)gameBase));
    ulong offsets[] = { 0xA8, 0x58, 0x38, 0x8, 0x0 };
	localPlayer = (ulong*)evaluatePointer((ulong)gameBase + 0x02FFAF50, offsets);
    //log("Got local player!" + std::to_string((ulong)localPlayer.address));
}

static void updateSDK() {
    ulong offsets[] = { 0xA8, 0x58, 0x38, 0x8, 0x0 };
    localPlayer.address = (ulong*)evaluatePointer((ulong)gameBase + 0x02FFAF50, offsets);
    std::stringstream stream;
    stream << "Got local player!" << std::hex << (ulong)localPlayer.address;
    log(stream.str());
}