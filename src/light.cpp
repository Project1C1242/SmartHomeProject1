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
if (isOn)
        throw DeviceStateException("Light is already ON!");
    isOn = true;
}

void Light::turnOff()
{
    if (!isOn)
        throw DeviceStateException("Light is already OFF!");
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

int Light::getBrightness() const {
    return brightness;
}

bool Light::getIsOn() const {
    return isOn;
}

void Light::update()
{
    cout << "Checking lightbulb connectivity..." << endl;
}
