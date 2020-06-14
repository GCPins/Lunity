#pragma once
#include <glm/glm.hpp>
#define PI 3.1415927f

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
	Vector3() { x = y = z = 0; }
	Vector3(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector3 sub(Vector3 vec) {
		Vector3 newVec;
		newVec.x = this->x - vec.x;
		newVec.y = this->y - vec.y;
		newVec.z = this->z - vec.z;
		return newVec;
	}
	Vector3 add(Vector3 vec) {
		Vector3 newVec;
		newVec.x = this->x + vec.x;
		newVec.y = this->y + vec.y;
		newVec.z = this->z + vec.z;
		return newVec;
	}
	Vector3 abs() {
		return Vector3(std::abs(x), std::abs(y), std::abs(z));
	}
	glm::vec3 toGlmVec() {
		return glm::vec3(x, y, z);
	}
	float DotProduct(Vector3 dst)
	{
		return x * dst.x + y * dst.y + z * dst.z;
	}
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
	Vector4() { x = y = z = w = 0; }
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
};
struct Matrix {
	union {
		float v[16];
		float v_n[4][4];
	};
	Matrix* correct() {
		Matrix* newMat = new Matrix;

		for (int i = 0; i < 4; i++) {
			newMat->v[i * 4 + 0] = v[0 + i];
			newMat->v[i * 4 + 1] = v[4 + i];
			newMat->v[i * 4 + 2] = v[8 + i];
			newMat->v[i * 4 + 3] = v[12 + i];
		}
		return newMat;
	};
	bool DirtyWorldToScreen(Vector3 origin, Vector3 pos, Vector2& screen, Vector2 fov, Vector2 displaySize)
	{
		pos = pos.sub(origin);

		float x = transformx(pos);
		float y = transformy(pos);
		float z = transformz(pos);

		if (z > 0)
			return false;

		float mX = (float)displaySize.x / 2.0F;
		float mY = (float)displaySize.y / 2.0F;

		screen.x = mX + (mX * x / -z * fov.x);
		screen.y = mY - (mY * y / -z * fov.y);

		return true;
	}
	bool DirtyWorldToScreenGH(Vector3 pos, Vector2& screen, int windowWidth, int windowHeight)
	{
		//Matrix-vector Product, multiplying world(eye) coordinates by projection matrix = clipCoords
		Vector4 clipCoords;
		clipCoords.x = pos.x * v[0] + pos.y * v[1] + pos.z * v[2] + v[3];
		clipCoords.y = pos.x * v[4] + pos.y * v[5] + pos.z * v[6] + v[7];
		clipCoords.z = pos.x * v[8] + pos.y * v[9] + pos.z * v[10] + v[11];
		clipCoords.w = pos.x * v[12] + pos.y * v[13] + pos.z * v[14] + v[15];

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
	float transformx(const Vector3& p) const
	{
		return p.x * v[0] + p.y * v[4] + p.z * v[8] + v[12];
	}
	float transformy(const Vector3& p) const
	{
		return p.x * v[1] + p.y * v[5] + p.z * v[9] + v[13];
	}
	float transformz(const Vector3& p) const
	{
		return p.x * v[2] + p.y * v[6] + p.z * v[10] + v[14];
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