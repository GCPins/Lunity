#pragma once
#include "../BigHead.h"

class SliderSetting
{
public:
	string text;
	float* value;
	float defaultVal;
	float min;
	float max;
	bool dragging;
	SliderSetting(string text);
	SliderSetting(string text, float* value);
	SliderSetting(string text, float* value, float min, float max);
	virtual void setValue(float value);
	virtual float getValue();
	virtual float getMin();
	virtual float getMax();
	virtual float getDefault();
};