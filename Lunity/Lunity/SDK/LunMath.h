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
			int x, y, z;
		};
		int arr[3];
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
	bool contains(float px, float py) {
		return x < px && y < py && z > px && w > py;
	}
	bool contains(Vector2 point) {
		return x < point.x && y < point.y && z > point.x && w > point.y;
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
struct Rect : Vector4 {
	float width;
	float height;
	Rect(float x, float y, float width, float height) : Vector4::Vector4(x, y, x + width, y + height) {
		this->width = width;
		this->height = height;
	}
	void setPos(float x, float y) {
		this->x = x;
		this->y = y;
		this->z = x + width;
		this->w = y + height;
	}
	void setPos(Vector2 pos) {
		this->x = pos.x;
		this->y = pos.y;
		this->z = pos.x + width;
		this->w = pos.y + height;
	}
	Rect add(float x, float y, float width, float height) {
		return Rect(this->x + x, this->y + y, this->width + width, this->height + height);
	}
};

class LunMath {
public:
	static float distanceVec3(Vector3 posA, Vector3 posB) {
		float dX = posA.x - posB.x;
		float dY = posA.y - posB.y;
		float dZ = posA.z - posB.z;

		return sqrt(dX * dX + dY * dY + dZ * dZ);
	}
	static Vector2 getRotationAnglesToEnt(Vector3 localPosition, Vector3 targetPosition) {
		Vector2 anglesVector;
		float dX = localPosition.x - targetPosition.x;
		float dY = localPosition.y - targetPosition.y;
		float dZ = localPosition.z - targetPosition.z;
		double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
		anglesVector.x = -(float)(atan2(dY, distance) * 180.0f / 3.141592653589793);
		anglesVector.y = (float)(atan2(dZ, dX) * 180.0f / 3.141592653589793) - 90.0f;
		return anglesVector;
	}
};