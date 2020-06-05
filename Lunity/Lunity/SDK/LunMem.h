#pragma once
#include "LunMC.h"
#define ulong UINT64
class LunMem
{
public:
	static ulong getBaseModule();
	static ClientInstance* getClientInstance();
	static ulong getThisModule();

	static void Patch(BYTE* dst, BYTE* src, unsigned int size);
	static void Nop(BYTE* dst, unsigned int size);
};

