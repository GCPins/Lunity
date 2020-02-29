#pragma once
#include <stdint.h>
#include "McSDK.h"
#define ulong uint64_t

class Player
{
public:
	ulong* address;
	Player(ulong* address) {
		this->address = address;
	}
	ulong onGroundAddress = *address + 0x178;
	byte* onGround = (byte*)(address + 0x178);
};

