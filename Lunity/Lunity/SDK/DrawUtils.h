#pragma once
#include "LunMem.h"
#include "LunMath.h"
#include "LunMC.h"

class DrawUtils
{
public:
	static void setCtx(MinecraftUIRenderContext* ctx, GuiData* gui);
	static GuiData* getGuiData();
	static BitmapFont* getFont();
	static float getTextWidth(std::string textStr, float size);
	static void flush();
	static void drawCoolText(Vector2 pos, std::string* textStr, float textSize);
	static void drawText(Vector2 pos, std::string* textStr, Color* color, float textSize);
	static void fillRectangle(Vector4 pos, const Vector4 col, float alpha);
	static void drawRectangle(Vector4 pos, Vector4 col, float alpha, float lineWidth);
	static bool DirtyWorldToScreen(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight);
	static bool WorldToScreen(Vector3 pos, Vector2& screen);
	static Color getRainbow(float progress);
};

