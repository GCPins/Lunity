// Created with ReClass.NET 1.2 by KN4CK3R
#pragma once
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
	char pad_0179[655]; //0x0179
}; //Size: 0x0408