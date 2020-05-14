#pragma once
// Created with ReClass.NET 1.2 by KN4CK3R

class ClientInstance
{
public:
	char pad_0008[232]; //0x0008
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
	char pad_0179[567]; //0x0179
	char Type[8]; //0x03B0
	char pad_03B8[160]; //0x03B8
	float PosX; //0x0458
	float PosY; //0x045C
	float PosZ; //0x0460
	char pad_0464[932]; //0x0464
}; //Size: 0x0808