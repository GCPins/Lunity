#pragma once
#include "pch.h"
#include "SliderSetting.h"

SliderSetting::SliderSetting(string text)
{
	this->text = text;
	this->value = NULL;
	this->min = 0.0f;
	this->max = 1.0f;
}

SliderSetting::SliderSetting(string text, float* value)
{
	this->text = text;
	this->value = value;
	this->min = 0.0f;
	this->max = 1.0f;
}

SliderSetting::SliderSetting(string text, float* value, float min, float max)
{
	this->text = text;
	this->value = value;
	this->min = min;
	this->max = max;
	this->defaultVal = *value;
}

void SliderSetting::setValue(float value)
{
	if (value > max) {
		*this->value = max;
		return;
	}
	if (value < min) {
		*this->value = min;
		return;
	}
	*this->value = value;
}

float SliderSetting::getValue()
{
	return *this->value;
}

float SliderSetting::getMin()
{
	return min;
}

float SliderSetting::getMax()
{
	return max;
}

float SliderSetting::getDefault()
{
	return defaultVal;
}
