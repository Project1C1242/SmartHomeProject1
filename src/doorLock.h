#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"

class DoorLock : public SmartDevice
{
private:
    bool locked;

public:
    DoorLock(string name, int id);

    void display() const override;
    void update() override;

    void lock();
    void unlock();
};

#endif