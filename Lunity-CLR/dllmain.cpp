// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")
#include <corerror.h>
#include <fstream>

LPCWSTR s2ws(const std::string& s)
{
    std::wstring stemp = std::wstring(s.begin(), s.end());
    return stemp.c_str();
}
DWORD WINAPI startClr(LPVOID lpParam)
{
	ICLRMetaHost* metaHost = NULL; //Declare our CLR Meta Host value as a NULL
	ICLRRuntimeInfo* runtimeInfo = NULL; //Declare our CLR Runtime Info as a Null
	ICLRRuntimeHost* runtimeHost = NULL; //Delcare our CLR HOST as a NULL

    if (CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&metaHost) == S_OK)
    {
        HRESULT mhostRes = metaHost->GetRuntime(L"v4.0.30319", IID_ICLRRuntimeInfo, (LPVOID*)&runtimeInfo);
        if (mhostRes == S_OK) //If getting Runtime version is successful
        {
            if (runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&runtimeHost) == S_OK) //If getting the interface with the follow parameters is successful
            {
                if (runtimeHost->Start() == S_OK) //Start the CLR (If it is successful)
                {
                    DWORD pReturnValue; //Declare our return value as a DWORD

                    //Invoke our method through CLR host using following parameters
                    std::string lunityPath = std::string(getenv("APPDATA") + std::string("\\Lunity\\Lunity-Injectable.dll"));
                    *(std::string*)(0x7FF790A61C3C) = lunityPath;
                    LPCWSTR managedDll = s2ws(lunityPath);
                    HRESULT hRes = runtimeHost->ExecuteInDefaultAppDomain(managedDll, L"Lunity_Injectable.EntryClass", L"Main", L"Hello!", &pReturnValue);
                    *(DWORD*)(0x7FF790A61C6C) = hRes;
                    *(DWORD*)(0x7FF790A61C94) = pReturnValue;
                    if (hRes == E_INVALIDARG) {
                        *(BYTE*)(0x7FF790A61CBC) = 1;
                    }
                    *(LPCWSTR*)(0x7FF790A61CE4) = managedDll;
                }
                else {
                    *(std::string*)(0x7FF790A61C64) = "Error starting host!";
                }
            }
            else {
                *(std::string*)(0x7FF790A61C64) = "Error getting interface!";
            }
        }
        else {
            *(std::string*)(0x7FF790A61C64) = "Error getting runtime!";
            *(HRESULT*)(0x7FF790A61C94) = mhostRes;
            if (mhostRes == E_POINTER) {
                *(BYTE*)(0x7FF790A61CBC) = 2;
            }
        }
    }
    else {
        *(std::string*)(0x7FF790A61C64) = "Error creating instance!";
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
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)startClr, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

