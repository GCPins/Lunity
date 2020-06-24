#pragma once
#include "LunMem.h"
#include "LunMath.h"
#include "LunMC.h"

class DrawUtils
{
public:
	static void setCtx(MinecraftUIRenderContext* ctx, GuiData* gui);
	static GuiData* getGuiData();
	static void cacheFont(BitmapFont* font);
	static void cacheCaretMeasure(int* data);
	static BitmapFont* getFont();
	static float getTextWidth(std::string textStr, float size);
	static void flush();
	static void drawCoolText(Vector2 pos, std::string* textStr, float textSize);
	static void drawText(Vector2 pos, std::string* textStr, Color* color, float textSize);
	static void fillRectangle(Vector4 pos, const Color col, float alpha);
	static void drawRectangle(Vector4 pos, Color col, float alpha, float lineWidth);
	static Color getRainbow(float progress);
};

