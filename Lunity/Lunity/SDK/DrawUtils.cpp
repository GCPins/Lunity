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

BitmapFont* cachedFont;
void DrawUtils::cacheFont(BitmapFont* font) {
	cachedFont = font;
}

int* cachedData;
void DrawUtils::cacheCaretMeasure(int* data)
{
	cachedData = data;
}

BitmapFont* DrawUtils::getFont()
{
	return LunMem::getClientInstance()->MinecraftGame->fifthFontIdk;
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

void DrawUtils::drawCoolText(Vector2 pos, std::string* textStr, float textSize)
{
	drawText(pos.add(Vector2(-2, -2)), textStr, new Color(0, 0, 0, 1), textSize);
	drawText(pos.add(Vector2(1, 1)), textStr, new Color(0, 0, 0, 1), textSize);
	drawText(pos, textStr, new Color(1, 1, 1, 1), textSize);
}

void DrawUtils::drawText(Vector2 pos, std::string* textStr, Color* color, float textSize)
{
	static Color* WHITE_COLOR = new Color(1, 1, 1, 1, false);
	if (color == nullptr)
		color = WHITE_COLOR;
	TextHolder* text = new TextHolder(textStr->c_str());
	BitmapFont* fontPtr = getFont();
	static uintptr_t caretMeasureData = 0xFFFFFFFF;

	float* posF = new float[4]; // Vector4(startX, startY, endX, endY);
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
					if (size != NULL) {
						renderctx->drawText(fontPtr, posF, text, color, 1.0f, 0, &size, &caretMeasureData);
					}
				}
			}
		}
	}

	if (color->deletable)
		delete color;
	delete[] posF;
	delete text;
}

void DrawUtils::fillRectangle(Vector4 pos, const Color col, float alpha)
{
	float* posF = new float[4]; // Vector4(startX, startY, endX, endY);
	posF[0] = pos.x;
	posF[1] = pos.z;
	posF[2] = pos.y;
	posF[3] = pos.w;

	Vector4* c = new Vector4(col);

	renderctx->fillRectangle(posF, reinterpret_cast<float*>(c), alpha);

	delete c;
	delete[] posF;
}

void DrawUtils::drawRectangle(Vector4 pos, Color col, float alpha, float lineWidth)
{
	lineWidth /= 2;
	fillRectangle(Vector4(pos.x - lineWidth, pos.y - lineWidth, pos.z + lineWidth, pos.y + lineWidth), col, alpha); // TOP
	fillRectangle(Vector4(pos.x - lineWidth, pos.y, pos.x + lineWidth, pos.w), col, alpha); // LEFT
	fillRectangle(Vector4(pos.z - lineWidth, pos.y, pos.z + lineWidth, pos.w), col, alpha); // 
	fillRectangle(Vector4(pos.x - lineWidth, pos.w - lineWidth, pos.z + lineWidth, pos.w + lineWidth), col, alpha);
}

Color DrawUtils::getRainbow(float progress)
{
	float div = (abs(progress / 1) * 6);
	float ascending = div / 1;
	float descending = 1.0f - ascending;

	switch ((int)div)
	{
	case 0:
		return Color(1, ascending, 0, 1);
	case 1:
		return Color(descending, 1, 0, 1);
	case 2:
		return Color(0, 1, ascending, 1);
	case 3:
		return Color(0, descending, 1, 1);
	case 4:
		return Color(ascending, 0, 1, 1);
	default: // case 5:
		return Color(1, 0, descending, 1);
	}
}