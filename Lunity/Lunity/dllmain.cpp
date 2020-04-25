// dllmain.cpp : Definisce il punto di ingresso per l'applicazione DLL.
#include "pch.h"
#include "BigHead.h"
#include "SDK/LunMem.h"
#include "Client/CheatManager.h"

void ExecLunity(LPVOID lpParam) {
    CheatManager* manager = new CheatManager();
    logHex("Module base", LunMem::getBaseModule());
    logHex("Client Instance", (ulong)LunMem::getClientInstance());
    logHex("LocalPlayer Address", (ulong)LunMem::getClientInstance()->localPlayer);
    while (true) {
        manager->tickCheats();
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ExecLunity, hModule, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

