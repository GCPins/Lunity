// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <metahost.h>
#pragma comment(lib, "mscoree.lib")
#include <corerror.h>
#include <fstream>

std::wstring s2ws(const std::string& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
    wchar_t* buf = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
    std::wstring r(buf);
    delete[] buf;
    return r;
}

uint64_t cc = 0x7FF6EAC91B24;

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
                    *(std::string*)(cc+80*2) = lunityPath;
                    std::wstring wlunityPath = s2ws(lunityPath);
                    *(LPCWSTR*)(cc + 80 * 3) = wlunityPath.c_str();
                    HRESULT hRes = runtimeHost->ExecuteInDefaultAppDomain((LPCWSTR)*wlunityPath.c_str(), L"Lunity_Injectable.EntryClass", L"Main", L"Hello!", &pReturnValue);
                    *(DWORD*)(cc + 80 * 4) = hRes;
                    *(DWORD*)(cc + 80 * 5) = pReturnValue;
                    if (hRes == E_INVALIDARG) {
                        *(BYTE*)(cc + 80 * 6) = 1;
                    }
                }
                else {
                    *(std::string*)(cc + 80 * 7) = "Error starting host!";
                }
            }
            else {
                *(std::string*)(cc + 80 * 7) = "Error getting interface!";
            }
        }
        else {
            *(std::string*)(cc + 80 * 7) = "Error getting runtime!";
            *(HRESULT*)(cc + 80 * 7) = mhostRes;
            if (mhostRes == E_POINTER) {
                *(BYTE*)(cc + 80 * 8) = 2;
            }
        }
    }
    else {
        *(std::string*)(cc + 80 * 7) = "Error creating instance!";
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

