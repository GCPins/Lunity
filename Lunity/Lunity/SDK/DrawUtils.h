#pragma once
#include "LunMC.h"

struct MC_Color {
	union {
		struct { float r, g, b, a; };
		float arr[4];
	};
	bool shouldDelete = true;

	MC_Color(const MC_Color& other) {
		this->r = other.r;
		this->g = other.g;
		this->b = other.b;
		this->a = other.a;
		this->shouldDelete = other.shouldDelete;
	}

	MC_Color(const float* arr) {
		this->arr[0] = arr[0];
		this->arr[1] = arr[1];
		this->arr[2] = arr[2];
		this->arr[3] = arr[3];
	};

	MC_Color(const float r, const float g, const float b, const float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	};

	MC_Color(const float r, const float g, const float b, const float a, const bool shouldDelete) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
		this->shouldDelete = shouldDelete;
	};
};

struct vec2_t
{
	float x, y;
	vec2_t() { x = y = 0; }
	vec2_t(float a, float b) : x(a), y(b) {}
	vec2_t& operator=(const vec2_t& copy) {
		x = copy.x;
		y = copy.y;
		return *this;
	}
	bool operator==(const vec2_t& o) const { return x == o.x && y == o.y; }
	bool operator!=(const vec2_t& o) const { return x != o.x || y != o.y; }

	vec2_t& sub(float f) { x -= f; y -= f; return *this; }
	vec2_t& div(float f) { x /= f; y /= f; return *this; }

	vec2_t& div(const vec2_t& o) { x /= o.x; y /= o.y; return *this; }
	vec2_t& mul(const vec2_t& o) { x *= o.x; y *= o.y; return *this; }
	vec2_t& mul(float f) { x *= f; y *= f; return *this; }

	vec2_t& sub(const vec2_t& o) { x -= o.x; y -= o.y; return *this; }
	vec2_t& add(const vec2_t& o) { x += o.x; y += o.y; return *this; }


	vec2_t& normAngles() {
		while (x > 89.9f)
			x -= 180.0f;
		while (x < -89.9f)
			x += 180.0f;

		while (y > 180.0f)
			y -= 360.0f;
		while (y < -180.0f)
			y += 360.0f;
		return *this;
	}

	float squaredlen() const { return x * x + y * y; }
	float magnitude() const { return sqrtf(squaredlen()); }
};

static MinecraftUIRenderContext* renderctx;

class DrawUtils
{
public:
	static void setCtx(MinecraftUIRenderContext* ctx) {
		renderctx = ctx;/*
		a2 = reinterpret_cast<__int64*>(renderctx)[2];
		tesselator = *reinterpret_cast<__int64*>(a2 + 0xA8);
		colorHolder = *reinterpret_cast<float**>(a2 + 0x30);*/
	}
	static BitmapFont* getFont() {
		return LunMem::getClientInstance()->MinecraftGame->leBetterFont;
	}
	static float getTextWidth(std::string textStr, float size) {
		TextHolder* text = new TextHolder(textStr);
		BitmapFont* font = getFont();
		float wid = renderctx->getLineLength(font, text, size, false);
		delete text;
		return wid;
	}
	static void flush() {
		renderctx->flushText(0);
	}
	static void drawCoolText(vec2_t pos, std::string* textStr, float textSize) {
		drawText(pos.add(vec2_t(-2, -2)), textStr, new MC_Color(0, 0, 0, 1), textSize);
		drawText(pos.add(vec2_t(1, 1)), textStr, new MC_Color(0, 0, 0, 1), textSize);
		drawText(pos, textStr, new MC_Color(1, 1, 1, 1), textSize);
	}
	static void drawText(vec2_t pos, std::string* textStr, MC_Color* color, float textSize)
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
								if(caretMeasureData != NULL)
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
};

