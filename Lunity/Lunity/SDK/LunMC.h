#pragma once
#include "../BigHead.h"
class LocalPlayer {
private:
	char pad_0178[0x174]; //0x0004
public:
	byte onGround;
};
class ClientInstance {
private:
	char pad_00F0[0xEC]; //0x0004
public:
	LocalPlayer* localPlayer; //0x00F0
};