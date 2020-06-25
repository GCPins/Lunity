// dllmain.cpp : Definisce il punto di ingresso per l'applicazione DLL.
#include "pch.h"
#include "BigHead.h"
#include "SDK/LunMem.h"
#include "Client/CheatManager.h"
#include "Client/Hooks/KeyHook.h"
#include "Client/Hooks/RenderHook.h"
#include "Client/Hooks/GamemodeHook.h"
#include "Client/Hooks/MouseHook.h"
#include "Client/Hooks/NetworkHook.h"
#include "Client/Hooks/TestHook.h"

#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")

void ExecLunity(LPVOID lpParam) {
    Logger::logHex("Module base", LunMem::getBaseModule());
    Logger::logHex("Client Instance", (ulong)LunMem::getClientInstance());
    Logger::logHex("LocalPlayer Address", (ulong)LunMem::getClientInstance()->LocalPlayer);


    CheatManager::loadCheats();
    if (MH_Initialize() == MH_OK)
    {
        Logger::log("Minhook init");
    }
    //TestHook::installHook();
    KeyHook::installHook();
    RenderHook::installHook();
    GamemodeHook::installHook();
    MouseHook::installHook();
    NetworkHook::installHook();
    while (true) {
        CheatManager::tickCheats();
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

