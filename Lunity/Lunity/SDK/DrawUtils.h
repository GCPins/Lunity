#pragma once
#include "LunMem.h"
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

#define PI ( 3.1415927f )
static constexpr float DEG_RAD2 = PI / 360.0f;
static constexpr float DEG_RAD = 180.0f / PI;
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
struct vec3_t
{
	union {
		struct {
			float x, y, z;
		};
		float floatArr[3];
	};


	vec3_t() { x = y = z = 0; }
	vec3_t(float a, float b, float c) : x(a), y(b), z(c) {}
	vec3_t(float a, float b) : x(a), y(b), z(0) {}
	vec3_t(const vec3_t& copy) {
		x = copy.x;
		y = copy.y;
		z = copy.z;
	}

	vec3_t& operator=(const vec3_t& copy) {
		x = copy.x;
		y = copy.y;
		z = copy.z;

		return *this;
	}


	vec3_t(float* v) : x(v[0]), y(v[1]), z(v[2]) {}

	bool iszero() const { return x == 0 && y == 0 && z == 0; }

	bool operator==(const vec3_t& o) const { return x == o.x && y == o.y && z == o.z; };
	bool operator!=(const vec3_t& o) const { return x != o.x || y != o.y || z != o.z; };
	vec3_t operator-() const { return vec3_t(-x, -y, -z); };

	vec3_t& mul(float f) { x *= f; y *= f; z *= f; return *this; };
	vec3_t& div(float f) { x /= f; y /= f; z /= f; return *this; };
	vec3_t& add(float f) { x += f; y += f; z += f; return *this; };
	vec3_t& sub(float f) { x -= f; y -= f; z -= f; return *this; };

	vec3_t& floor() {
		x = floorf(x);
		y = floorf(y);
		z = floorf(z);
		return *this;
	};

	vec3_t& add(const vec3_t& o) { x += o.x; y += o.y; z += o.z; return *this; }
	vec3_t& sub(const vec3_t& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }

	float squaredlen() const { return x * x + y * y + z * z; }
	float squaredxzlen() const { return x * x + z * z; }

	vec3_t lerp(const vec3_t other, float val) {
		vec3_t ne;
		ne.x = x + val * (other.x - x);
		ne.y = y + val * (other.y - y);
		ne.z = z + val * (other.z - z);
		return ne;
	}

	float sqrxy() const { return x * x + y * y; }

	float dot(const vec3_t& o) const { return x * o.x + y * o.y + z * o.z; }
	float dotxy(const vec3_t& o) const { return x * o.x + y * o.y; }

	float magnitude() const { return sqrtf(squaredlen()); }

	vec3_t& normalize() { div(magnitude()); return *this; }

	float dist(const vec3_t& e) const { vec3_t t; return dist(e, t); }

	float dist(const vec3_t& e, vec3_t& t) const { t = *this; t.sub(e); return t.magnitude(); }

	float Get2DDist(const vec3_t& e) const { float dx = e.x - x, dy = e.y - y; return sqrtf(dx * dx + dy * dy); }

	float magnitudexy() const { return sqrtf(x * x + y * y); }
	float magnitudexz() const { return sqrtf(x * x + z * z); }

	vec3_t& cross(const vec3_t& a, const vec3_t& b) { x = a.y * b.z - a.z * b.y; y = a.z * b.x - a.x * b.z; z = a.x * b.y - a.y * b.x; return *this; }
	float cxy(const vec3_t& a) { return x * a.y - y * a.x; }

	vec2_t CalcAngle(vec3_t dst)
	{
		vec3_t diff = dst.sub(*this);

		diff.y = diff.y / diff.magnitude();
		vec2_t angles;
		angles.x = asinf(diff.y) * -DEG_RAD;
		angles.y = (float)-atan2f(diff.x, diff.z) * DEG_RAD;

		return angles;
	}
	vec3_t DifferenceAngle(vec3_t to)
	{
		vec3_t add;
		add.x = to.x - this->x;
		add.y = to.y - this->y;
		return add;
	}
	float DifferenceOfAngles(vec3_t to)
	{
		vec3_t from = *this;
		vec3_t vdifference;
		vdifference.y = from.y - to.y;
		vdifference.x = from.x - to.x;

		//normalize by making them positive values if they are negative
		if (vdifference.y < 0)
		{
			vdifference.y *= -1;
		}
		if (vdifference.x < 0)
		{
			vdifference.x *= -1;
		}

		//add them together and divide by 2, gives an average of the 2 angles
		float fDifference = (vdifference.y + vdifference.x) / 2;
		return fDifference;
	}
	vec3_t scaleFixedPoint(float scalex, float scaley, vec3_t fixedPoint)
	{
		vec3_t newvec;
		newvec.x = x * scalex + fixedPoint.x * (1 - scalex);
		newvec.y = y * scaley + fixedPoint.y * (1 - scaley);
		return newvec;
	}


	bool WorldToScreen2(float fovx, float fovy, float windowWidth, float windowHeight, vec3_t left, vec3_t up, vec3_t forward, vec3_t origin, vec3_t& screen)
	{
		vec3_t transform;
		float xc, yc;
		float px, py;
		float zO;

		px = (float)tan(fovx * DEG_RAD2);
		py = (float)tan(fovy * DEG_RAD2);

		transform = this->sub(origin); //this = destination

		xc = windowWidth / 2.0f;
		yc = windowHeight / 2.0f;

		zO = transform.dot(left);
		if (zO <= 0.1) { return false; }

		screen.x = xc - transform.dot(up) * xc / (zO * px);
		screen.y = yc - transform.dot(forward) * yc / (zO * py);
		return true;
	}
};
struct vec4_t
{
	union
	{
		struct { float x, y, z, w; };
		float v[4];
	};
	vec4_t() { x = 0, y = 0, z = 0, w = 0; }
	explicit vec4_t(const vec3_t& p, float w = 0) : x(p.x), y(p.y), z(p.z), w(w) {};
	vec4_t(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
	float& operator[](int i) { return v[i]; };
	float  operator[](int i) const { return v[i]; };

	inline bool contains(vec2_t* point) {
		/*
		Assumes:
			start: vec2_t(x, y)
			end:   vec2_t(z, w)
			start < end
		*/
		vec2_t start = vec2_t(x, y);
		vec2_t end = vec2_t(z, w);

		if (point->x <= start.x || point->y <= start.y)
			return false;

		if (point->x >= end.x || point->y >= end.y)
			return false;
		return true;
	};
};

class DrawUtils
{
public:
	static void setCtx(MinecraftUIRenderContext* ctx, GuiData* gui);
	static GuiData* getGuiData();
	static BitmapFont* getFont();
	static float getTextWidth(std::string textStr, float size);
	static void flush();
	static void drawCoolText(vec2_t pos, std::string* textStr, float textSize);
	static void drawText(vec2_t pos, std::string* textStr, MC_Color* color, float textSize);
	static void fillRectangle(vec4_t pos, const MC_Color col, float alpha);
	static void drawRectangle(vec4_t pos, MC_Color col, float alpha, float lineWidth);
	static vec2_t DirtyWorldToScreen(vec3_t pos, float matrix[16], int windowWidth, int windowHeight);
};

