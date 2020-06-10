#include "Setting.h"

Setting::Setting()
{
	this->value = 0;
}
Setting::Setting(double value)
{
	this->value = value;
}

void Setting::setValue(double value)
{
	this->value = value;
}

double Setting::getValue()
{
	return value;
}
