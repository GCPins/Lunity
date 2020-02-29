#include "Cheat.h"

bool wasEnabled = false;

Cheat::Cheat()
{

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
