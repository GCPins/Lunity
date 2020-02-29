#include "Cheat.h"

bool wasEnabled = false;

Cheat::Cheat(std::string name, bool enabled, char keybind)
{
    this->name = name;
    this->enabled = enabled;
    this->keybind = keybind;
}

void Cheat::onLoop()
{
    if (wasEnabled != enabled)
    {
        if (enabled == false)
        {
            onDisable();
        }
        else
        {
            onEnable();
        }
        wasEnabled = enabled;
    }
    if (enabled)
    {
        onTick();
    }
}

void Cheat::onTick()
{
}

void Cheat::onEnable()
{
}

void Cheat::onDisable()
{
}