#pragma once
#include "../../BigHead.h"
#include <Windows.h>
#include <atlbase.h>
#include <Shlobj.h>
#include <string>

class AssetHook
{
public:
	static void installHook();
	static void uninstallHook();
};

