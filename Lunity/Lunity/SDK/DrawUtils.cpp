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

vec3_t Subtract(vec3_t src, vec3_t dst)
{
	vec3_t diff;
	diff.x = src.x - dst.x;
	diff.y = src.y - dst.y;
	diff.z = src.z - dst.z;
	return diff;
}
float DotProduct(vec3_t src, vec3_t dst)
{
	return src.x * dst.x + src.y * dst.y + src.z * dst.z;
}
vec3_t* directionalVector(float yaw, float pitch)
{
	vec3_t* vec3 = new vec3_t();
	vec3->x = (float)cos(yaw) * (float)cos(pitch);
	vec3->y = (float)sin(pitch);
	vec3->z = (float)sin(yaw) * (float)cos(pitch);
	return vec3;
}

bool DirtyWorldToScreen(vec3_t src, vec3_t dst, vec2_t& screen, float fovx, float fovy, float windowWidth, float windowHeight, vec3_t left, vec3_t up, vec3_t forward)
{
	vec3_t transform;
	float xc, yc;
	float px, py;
	float z;

	px = tan(fovx * PI / 360.0);
	py = tan(fovy * PI / 360.0);

	transform = Subtract(dst, src);

	xc = windowWidth / 2.0;
	yc = windowHeight / 2.0;

	z = DotProduct(transform, left);

	if (z <= 0.1)
	{
		return false;
	}

	screen.x = xc - DotProduct(transform, up) * xc / (z * px);
	screen.y = yc - DotProduct(transform, forward) * yc / (z * py);

	return true;
}

bool DrawUtils::WorldToScreen(vec3_t pos, vec2_t& screen)
{
	ClientInstance* ci = LunMem::getClientInstance();
	LocalPlayer* lp = ci->LocalPlayer;
	GuiData* gd = getGuiData();
	LevelRenderer* lr = ci->LevelRenderer;
	Vector3 origin = lr->Origin;
	vec3_t origVec3t(origin.x, origin.y, origin.z);
	vec3_t* forward = directionalVector(lp->LookingVec.y, lp->LookingVec.x);
	vec3_t* left = directionalVector(lp->LookingVec.y+90, lp->LookingVec.x);
	vec3_t* up = directionalVector(lp->LookingVec.y, lp->LookingVec.x+90);
	return DirtyWorldToScreen(origVec3t, pos, screen, ci->fovX, ci->fovY, gd->Resolution.x, gd->Resolution.y, *left, *up, *forward);
}

