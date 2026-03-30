#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice
{
private:
    float temperature;

public:
    Thermostat(string name, int id);
    int getTemperature() const;

    // Overriding the pure virtual functions from SmartDevice
    void display() const override;
    void update() override;

    void setTemperature(float temp);
};

#endif