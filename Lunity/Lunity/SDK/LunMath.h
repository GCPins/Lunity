#pragma once
class VRectI {
public:
	int x=0;
	int y=0;
	int width=0;
	int height=0;

	VRectI(){}
	VRectI(int x, int y, int width, int height)
	{
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	bool contains(int cx, int cy) {
		return cx > x && cy > y && cx < x + width && cy < y + height;
	}

	VRectI add(int ax, int ay, int awidth, int aheight) {
		return VRectI(x + ax, y + ay, width + awidth, height + aheight);
	}

	/*vec4_t toVec4() {
		return vec4_t(x, y, x+width, x+height);
	}
	vec2_t getPos() {
		return vec2_t(x, y);
	}*/
};