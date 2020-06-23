#include "pch.h"
#include "LunMem.h"

ulong LunMem::getBaseModule()
{
	return (ulong)GetModuleHandle(NULL);
}

ClientInstance* LunMem::getClientInstance()
{
	ulong baseOffset = 0x0389A940;
	return (ClientInstance*)*(ulong*)((*(ulong*)(getBaseModule() + baseOffset))+0x38);
}

ulong LunMem::getThisModule()
{
	return (ulong)GetModuleHandleA("Lunity.dll");
}

void LunMem::Patch(BYTE* dst, BYTE* src, unsigned int size)
{
    DWORD oldprotect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);

    memcpy(dst, src, size);
    VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void LunMem::Nop(BYTE* dst, unsigned int size)
{
    DWORD oldprotect;
    VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
    memset(dst, 0x90, size);
    VirtualProtect(dst, size, oldprotect, &oldprotect);
}