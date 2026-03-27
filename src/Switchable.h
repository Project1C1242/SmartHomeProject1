#ifndef SWITCHABLE_H
#define SWITCHABLE_H

class Switchable
{
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Switchable() {}
};

#endif