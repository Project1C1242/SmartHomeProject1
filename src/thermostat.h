#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice
{
private:
    float temperature;

public:
    Thermostat(string name, int id);

    void display() const override;
    void update() override;

    void setTemperature(float temp);
};

#endif