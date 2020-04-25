#include "pch.h"
#include "LunMem.h"

ulong LunMem::getBaseModule()
{
	return (ulong)GetModuleHandle(NULL);
}

ClientInstance* LunMem::getClientInstance()
{
	ulong baseOffset = 0x0307D3A0;
	return (ClientInstance*)*(ulong*)((*(ulong*)(getBaseModule() + baseOffset))+0x30);
}
