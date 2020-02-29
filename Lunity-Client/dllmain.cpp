// dllmain.cpp : Defines the entry point for the DLL application.
#include "ClientBase/SDK/McSDK.h"
#include "ClientBase/CheatHandler.h"
#include "ClientBase/SDK/Logger.h"

DWORD WINAPI startLunity(LPVOID lpParam)
{
    log("Starting lunity...");
    initSDK();
    log("SDK started!");
    loadCheats();
    while (1) {
        tickCheats();
        updateSDK();
        if (localPlayer.address != 0) {
            //*localPlayer.onGround = 1;
            log("Airjump addr!" + localPlayer.onGroundAddress);
        }
    }
    return 0;
}

BOOL __stdcall DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)startLunity, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

