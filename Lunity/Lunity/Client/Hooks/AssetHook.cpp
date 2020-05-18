#include "pch.h"
#include "AssetHook.h"
#include <MinHook.h>

wstring assetsDir = wstring(L"C:\Program Files\WindowsApps\Microsoft.MinecraftUWP_1.14.6005.0_x64__8wekyb3d8bbwe\data");
wstring swapDir;

FARPROC hFunc;

// Basic hook setup for CreateFileW
typedef HANDLE(WINAPI* PfnCreateFileW)(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate);
PfnCreateFileW pfnCreateFileW = NULL; // Will hold the trampoline to the original CreateFileW function
// CreateFileW hook function
HANDLE WINAPI HfnCreateFileW(LPCWSTR lpFilename, DWORD dwAccess, DWORD dwSharing, LPSECURITY_ATTRIBUTES saAttributes, DWORD dwCreation, DWORD dwAttributes, HANDLE hTemplate)
{
	wstring filePath(lpFilename);

	// Check if the app is accessing protected resources
	if (filePath.find(assetsDir) != filePath.npos)
	{
		std::wstring newPath(swapDir);

		// Windows provides the app the location of the WindowsApps directory, so the first half the file path will use back slashes
		// After that, some apps will use back slashes while others use forward slashes so be aware of what the app uses
		newPath += filePath.substr(filePath.find(L"\\", assetsDir.size()) + 1, filePath.size());

		// Check if the file being accessed exists at the new path and reroute access to that file
		// Don't reroute directories as bad things can happen such as directories being ghost locked
		if (PathFileExists(newPath.c_str()) && !PathIsDirectory(newPath.c_str()))
			return pfnCreateFileW(newPath.c_str(), dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
	}

	// Let the app load other files normally
	return pfnCreateFileW(lpFilename, dwAccess, dwSharing, saAttributes, dwCreation, dwAttributes, hTemplate);
}

void AssetHook::installHook()
{
	Logger::log("Creating asset hook...");
	string appdataDir = getenv("APPDATA");
	wstring wappdata = wstring(appdataDir.begin(), appdataDir.end());
	swapDir = wstring(wappdata + wstring(L"\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\LunSwap"));

	HMODULE KernelBase = GetModuleHandleA("KernelBase.dll");
	hFunc = GetProcAddress(KernelBase, "CreateFileW");

	if (MH_CreateHook(hFunc, &HfnCreateFileW, reinterpret_cast<LPVOID*>(&pfnCreateFileW)) != MH_OK) {
		Logger::log("Failed creating create file hook!");
		return;
	}

	if (MH_EnableHook(hFunc) != MH_OK) {
		Logger::log("Failed enabling create file hook!");
		return;
	}

	Logger::log("Asset hook successfully made!");
}

void AssetHook::uninstallHook()
{
	string appdataDir = getenv("APPDATA");
	wstring wappdata = wstring(appdataDir.begin(), appdataDir.end());
	swapDir = wstring(wappdata + wstring(L"\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\LunSwap"));

	HMODULE KernelBase = GetModuleHandleA("KernelBase.dll");
	hFunc = GetProcAddress(KernelBase, "CreateFileW");

	MH_DisableHook(hFunc);
}
