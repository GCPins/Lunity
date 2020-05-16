#include "pch.h"
#include "RenderHook.h"
#include "../../SDK/LunMem.h"
#include "../../SDK/LunMC.h"
#include "../../SDK/DrawUtils.h"
#include "../../Logger.h"
#include "../CheatManager.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")

typedef int (WINAPI* RenderText)(__int64 a1, MinecraftUIRenderContext* renderCtx);
RenderText original;

float entireW = 0;
int hookCallback(__int64 a1, MinecraftUIRenderContext* renderCtx) {
	DrawUtils::setCtx(renderCtx);

	CheatManager::onPreRender();

	DrawUtils::flush();
	int ret = original(a1, renderCtx);

	CheatManager::onPostRender();

	DrawUtils::flush();
	return ret;
}

void RenderHook::installHook() {
	log("installing render hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0x7235A0);
	logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		log("Render Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			log("render hook installed");
		}
	}
	if (!installSuccess) {
		log("Failed to hook render!");
	}
}

void RenderHook::uninstallHook()
{
	void* toHook = (void*)(LunMem::getBaseModule() + 0x7235A0);
	MH_DisableHook(toHook);
}
