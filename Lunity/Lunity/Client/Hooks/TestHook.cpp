#include "pch.h"
#include "../../SDK/DrawUtils.h"
#include "../../SDK/LunMem.h"
#include "../../SDK/LunMC.h"
#include "../../Logger.h"
#include <MinHook.h>
#pragma comment(lib, "libMinHook.lib")
#include "TestHook.h"

typedef int(__thiscall* TestFunc)(MinecraftUIRenderContext* renderCtx, BitmapFont* font,
	Vector4* pos, TextHolder* text, Color* color, float alpha,
	long textAlignment, float* textMeasureData, int* caretMeasureData);
TestFunc original;

int __fastcall hookCallback(MinecraftUIRenderContext* renderCtx, BitmapFont* font,
	Vector4* pos, TextHolder* text, Color* color, float alpha,
	long textAlignment, float* textMeasureData, int* caretMeasureData) {

	/*DrawUtils::cacheFont(font);
	DrawUtils::cacheCaretMeasure(caretMeasureData);*/

	/*Logger::logHex("Context", (ulong)renderCtx);
	Logger::logHex("font", (ulong)font);
	Logger::logHex("pos", (ulong)pos);
	Logger::logHex("text", (ulong)text);
	Logger::logHex("color", (ulong)color);
	Logger::logHex("alpha", (ulong)alpha);
	Logger::logHex("textAlignment", (ulong)textAlignment);
	Logger::logHex("textMeasureData", (ulong)*textMeasureData);
	Logger::logHex("caretMeasureData", (ulong)caretMeasureData);*/


	//static float size = 1;

	//int max = 0xFFFFFFFF;

	//original(renderCtx, font, new Vector4(0,1000,0,1000), new TextHolder("GG"), new Color(1,1,1,1), 1.0f, 0, &size, &max);
	//original(renderCtx, font, new Vector4(0, 1000, 0, 1000), new TextHolder("LunityXXXXXXXXXXXX"), new Color(1, 1, 1, 1), 1.0f, 0, &size, &max);

	return original(renderCtx, font, pos, text, color, alpha, textAlignment, textMeasureData, caretMeasureData);
}

void TestHook::installHook()
{
	Logger::log("installing test hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0xB2DF70);
	Logger::logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		Logger::log("test Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			Logger::log("test hook installed");
		}
	}
	if (!installSuccess) {
		Logger::log("Failed to hook test!");
	}
}

void TestHook::uninstallHook()
{
	void* toHook = (void*)(LunMem::getBaseModule() + 0xB2DF70);
	MH_DisableHook(toHook);
}
