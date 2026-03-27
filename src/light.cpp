#include <iostream>
#include "Light.h"
#include "Exceptions.h"

using namespace std;

Light::Light(string name, int id) : SmartDevice(name, id)
{
    isOn = false;
    brightness = 50;
}

void Light::turnOn()
{
    isOn = true;
}

void Light::turnOff()
{
    isOn = false;
}

void Light::setBrightness(int level)
{
    if (level < 0 || level > 100)
        throw InvalidValueException();

    brightness = level;
}

void Light::display() const
{
    cout << "Light [" << getName() << "] "
         << (isOn ? "ON" : "OFF")
         << " Brightness: " << brightness << endl;
}

void Light::update()
{
}