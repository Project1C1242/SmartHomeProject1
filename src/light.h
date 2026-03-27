#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include "Switchable.h"

class Light : public SmartDevice, public Switchable
{
private:
    bool isOn;
    int brightness;

public:
    Light(string name, int id);

    void display() const override;
    void update() override;

    void turnOn() override;
    void turnOff() override;

    void setBrightness(int level);
};

#endif