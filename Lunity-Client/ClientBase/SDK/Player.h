#pragma once
#include <stdint.h>
#define ulong uint64_t
class Player
{
	ulong* address;
public:
	ulong* address;
	Player(ulong* address) {
		this->address = address;
	}
	ulong onGroundAddress = *address + 0x178;
	byte* onGround = (byte*)(address + 0x178);
};

