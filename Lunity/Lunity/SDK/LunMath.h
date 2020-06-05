#pragma once

struct Vector2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};
	Vector2() { x = y = 0; }
	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}
	Vector2 add(Vector2 toAdd) {
		float newX = x + toAdd.x;
		float newY = y + toAdd.y;
		return Vector2(newX, newY);
	}
};
struct Vector3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};
};
struct Vector3i {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};
};
struct Vector4 {
	union{
		struct {
			float x, y, z, w;
		};
		float arr[4];
	};
	Vector4(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
	float* toArr() {
		return arr;
	}
};
struct Color : Vector4 {
	bool deletable;
	Color(float x, float y, float z, float w, bool deletable) : Vector4::Vector4(x, y, z, w) {
		this->deletable = deletable;
	}
	Color(float x, float y, float z, float w) : Vector4::Vector4(x, y, z, w) {
		this->deletable = false;
	}
};

class LunMath {
public:
	static float distanceVec3(Vector3 posA, Vector3 posB) {
		return 0;
	}
};