#pragma once
#include <stdint.h>
#include "McSDK.h"
#define ulong uint64_t

class Player
{
public:
	ulong address;
	Player(ulong address) {
		this->address = address;
	}
	byte* onGround = (byte*)(address + 0x178);
};

