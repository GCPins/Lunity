#pragma once
#include <stdint.h>
#define ulong uint64_t
class Player
{
	ulong* address;
public:
	Player(ulong* address) {
		this->address = address;
	}
	bool* onGround = (bool*)(address + 0x178);
};

