#include "SmartDevice.h"

SmartDevice::SmartDevice(string name, int id) : name(name), id(id) {}

int SmartDevice::getID() const
{
    return id;
}

string SmartDevice::getName() const
{
    return name;
}
