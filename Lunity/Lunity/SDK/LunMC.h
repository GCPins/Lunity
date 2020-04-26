#pragma once
#define uint UINT32
class LocalPlayer {
private:
	char pad_0178[0x178]; //0x0004
public:
	uint onGround;
};
class ClientInstance {
private:
	char pad_00F0[0xEC]; //0x0004
public:
	LocalPlayer* localPlayer; //0x00F0
};