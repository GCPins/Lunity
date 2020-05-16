#pragma once
#include "LunMC.h"
#define ulong UINT64
class LunMem
{
public:
	static ulong getBaseModule();
	static ClientInstance* getClientInstance();
	static ulong getThisModule();
};

