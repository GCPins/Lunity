#pragma once
// Created with ReClass.NET 1.2 by KN4CK3R

class ClientInstance
{
public:
	char pad_0008[88]; //0x0008
	class MinecraftGame* MinecraftGame; //0x0060
	char pad_0068[136]; //0x0068
	class LocalPlayer* LocalPlayer; //0x00F0
	char pad_00F8[5933]; //0x00F8

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x1825

class LocalPlayer
{
public:
	char pad_0000[376]; //0x0000
	bool OnGround; //0x0178
	char pad_0179[439]; //0x0179
	class MultiPlayerLevel* MultiPlayerLevel; //0x0330
	char pad_0338[120]; //0x0338
	char Type[8]; //0x03B0
	char pad_03B8[160]; //0x03B8
	float PosX; //0x0458
	float PosY; //0x045C
	float PosZ; //0x0460
	float PosX2; //0x0464
	float PosY2; //0x0468
	float PosZ2; //0x046C
	int32_t N000006E7; //0x0470
	float HitboxWidth; //0x0474
	float HitboxHeight; //0x0478
	char pad_047C[892]; //0x047C
}; //Size: 0x07F8

class MultiPlayerLevel
{
public:
	char pad_0000[2128]; //0x0000
	int32_t N000008BE; //0x0850
	int32_t LookingBlockSide; //0x0854
	int32_t LookingBlockX; //0x0858
	int32_t LookingBlockY; //0x085C
	int32_t LookingBlockZ; //0x0860
	char pad_0864[12]; //0x0864
	class Actor* LookingActor; //0x0870
	char pad_0878[1936]; //0x0878
}; //Size: 0x1008

class Actor
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class MinecraftGame
{
public:
	char pad_0000[56]; //0x0000
	class MinecraftGraphics* MinecraftGraphics; //0x0038
	char pad_0040[1992]; //0x0040
}; //Size: 0x0808

class MinecraftGraphics
{
public:
	char pad_0008[2048]; //0x0008

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0808