#include <iostream>
#include "Thermostat.h"
#include "Exceptions.h"

using namespace std;

Thermostat::Thermostat(string name, int id) : SmartDevice(name, id)
{
    temperature = 70.0;
}

void Thermostat::setTemperature(float temp)
{
    if (temp < 50 || temp > 90)
        throw InvalidValueException();

    temperature = temp;
}

void Thermostat::display() const
{
    cout << "Thermostat [" << getName() << "] "
         << "Temp: " << temperature << endl;
}

void Thermostat::update()
{  
}