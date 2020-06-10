#pragma once

enum class SettingType {
	Slider,
	Checkbox,

};


class Setting
{
public:
	double value;
	Setting();
	Setting(double value);
	virtual void setValue(double value);
	virtual double getValue();
};