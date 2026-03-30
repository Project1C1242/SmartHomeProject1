#include <iostream>
#include "Thermostat.h"
#include "Exceptions.h"

using namespace std;

// Pass the name and id up to the SmartDevice constructor
Thermostat::Thermostat(string name, int id) : SmartDevice(name, id)
{
    temperature = 68; //default temp
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
         << "Current Temp: " << temperature <<" F" << endl;
}

int Thermostat::getTemperature() const {
    return temperature; 
}

void Thermostat::update()
{  
}