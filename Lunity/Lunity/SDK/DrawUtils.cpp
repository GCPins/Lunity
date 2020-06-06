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
	TextHolder* text = new TextHolder(*textStr);
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
					if (color->toArr() != NULL) {
						if (size != NULL) {
							if (caretMeasureData != NULL)
								renderctx->drawText(fontPtr, posF, text, color->toArr(), 1, 0, &size, &caretMeasureData);
						}
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

void DrawUtils::fillRectangle(Vector4 pos, const Vector4 col, float alpha)
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

void DrawUtils::drawRectangle(Vector4 pos, Vector4 col, float alpha, float lineWidth)
{
	lineWidth /= 2;
	fillRectangle(Vector4(pos.x - lineWidth, pos.y - lineWidth, pos.z + lineWidth, pos.y + lineWidth), col, alpha); // TOP
	fillRectangle(Vector4(pos.x - lineWidth, pos.y, pos.x + lineWidth, pos.w), col, alpha); // LEFT
	fillRectangle(Vector4(pos.z - lineWidth, pos.y, pos.z + lineWidth, pos.w), col, alpha); // 
	fillRectangle(Vector4(pos.x - lineWidth, pos.w - lineWidth, pos.z + lineWidth, pos.w + lineWidth), col, alpha);
}

bool DrawUtils::DirtyWorldToScreen(Vector3 pos, Vector2& screen, float matrix[16], int windowWidth, int windowHeight)
{
	//Matrix-vector Product, multiplying world(eye) coordinates by projection matrix = clipCoords
	Vector4 clipCoords;
	clipCoords.x = pos.x * matrix[0] + pos.y * matrix[1] + pos.z * matrix[2] + matrix[3];
	clipCoords.y = pos.x * matrix[4] + pos.y * matrix[5] + pos.z * matrix[6] + matrix[7];
	clipCoords.z = pos.x * matrix[8] + pos.y * matrix[9] + pos.z * matrix[10] + matrix[11];
	clipCoords.w = pos.x * matrix[12] + pos.y * matrix[13] + pos.z * matrix[14] + matrix[15];

	if (clipCoords.w < 0.1f)
		return false;

	//perspective division, dividing by clip.W = Normalized Device Coordinates
	Vector3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;

	screen.x = (windowWidth / 2 * NDC.x) + (NDC.x + windowWidth / 2);
	screen.y = -(windowHeight / 2 * NDC.y) + (NDC.y + windowHeight / 2);
	return true;
}

bool DrawUtils::WorldToScreen(Vector3 pos, Vector2& screen)
{
	/*ClientInstance* ci = LunMem::getClientInstance();
	LocalPlayer* lp = ci->LocalPlayer;
	GuiData* gd = getGuiData();
	LevelRenderer* lr = ci->LevelRenderer;
	Vector3 origin = lr->Origin;
	Vector3 origVec3t(origin.x, origin.y, origin.z);
	Vector3* forward = directionalVector(lp->LookingVec.y, lp->LookingVec.x);
	Vector3* left = directionalVector(lp->LookingVec.y+90, lp->LookingVec.x);
	Vector3* up = directionalVector(lp->LookingVec.y, lp->LookingVec.x+90);
	return DirtyWorldToScreen(origVec3t, pos, screen, ci->fovX, ci->fovY, gd->Resolution.x, gd->Resolution.y, *left, *up, *forward);*/
	return false;
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
