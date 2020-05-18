#include "pch.h"
#include "DrawUtils.h"

static MinecraftUIRenderContext* renderctx;
static GuiData* guiData;

void DrawUtils::setCtx(MinecraftUIRenderContext* ctx, GuiData* gui)
{
	renderctx = ctx;
	guiData = gui;
}

GuiData* DrawUtils::getGuiData() {
	return guiData;
}

BitmapFont* DrawUtils::getFont()
{
	return LunMem::getClientInstance()->MinecraftGame->leBetterFont;
}

float DrawUtils::getTextWidth(std::string textStr, float size)
{
	TextHolder* text = new TextHolder(textStr);
	BitmapFont* font = getFont();
	float wid = renderctx->getLineLength(font, text, size, false);
	delete text;
	return wid;
}

void DrawUtils::flush()
{
	renderctx->flushText(0);
}

void DrawUtils::drawCoolText(vec2_t pos, std::string* textStr, float textSize)
{
	drawText(pos.add(vec2_t(-2, -2)), textStr, new MC_Color(0, 0, 0, 1), textSize);
	drawText(pos.add(vec2_t(1, 1)), textStr, new MC_Color(0, 0, 0, 1), textSize);
	drawText(pos, textStr, new MC_Color(1, 1, 1, 1), textSize);
}

void DrawUtils::drawText(vec2_t pos, std::string* textStr, MC_Color* color, float textSize)
{
	static MC_Color* WHITE_COLOR = new MC_Color(1, 1, 1, 1, false);
	if (color == nullptr)
		color = WHITE_COLOR;
	TextHolder* text = new TextHolder(*textStr);
	BitmapFont* fontPtr = getFont();
	static uintptr_t caretMeasureData = 0xFFFFFFFF;

	float* posF = new float[4]; // vec4_t(startX, startY, endX, endY);
	posF[0] = pos.x;
	posF[1] = pos.x + 1000;
	posF[2] = pos.y;
	posF[3] = pos.y + 1000;

	static float size = 1;
	size = textSize;
	if (fontPtr != NULL) {
		if (posF != NULL) {
			if (text != NULL) {
				if (color != NULL) {
					if (color->arr != NULL) {
						if (size != NULL) {
							if (caretMeasureData != NULL)
								renderctx->drawText(fontPtr, posF, text, color->arr, 1, 0, &size, &caretMeasureData);
						}
					}
				}
			}
		}
	}

	if (color->shouldDelete)
		delete color;
	delete[] posF;
	delete text;
}

void DrawUtils::fillRectangle(vec4_t pos, const MC_Color col, float alpha)
{
	float* posF = new float[4]; // vec4_t(startX, startY, endX, endY);
	posF[0] = pos.x;
	posF[1] = pos.z;
	posF[2] = pos.y;
	posF[3] = pos.w;

	MC_Color* c = new MC_Color(col);

	renderctx->fillRectangle(posF, reinterpret_cast<float*>(c), alpha);

	delete c;
	delete[] posF;
}

void DrawUtils::drawRectangle(vec4_t pos, MC_Color col, float alpha, float lineWidth)
{
	lineWidth /= 2;
	fillRectangle(vec4_t(pos.x - lineWidth, pos.y - lineWidth, pos.z + lineWidth, pos.y + lineWidth), col, alpha); // TOP
	fillRectangle(vec4_t(pos.x - lineWidth, pos.y, pos.x + lineWidth, pos.w), col, alpha); // LEFT
	fillRectangle(vec4_t(pos.z - lineWidth, pos.y, pos.z + lineWidth, pos.w), col, alpha); // 
	fillRectangle(vec4_t(pos.x - lineWidth, pos.w - lineWidth, pos.z + lineWidth, pos.w + lineWidth), col, alpha);
}