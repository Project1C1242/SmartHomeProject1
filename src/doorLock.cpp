#include <iostream>
#include "DoorLock.h"
#include "Exceptions.h"

using namespace std;

DoorLock::DoorLock(string name, int id) : SmartDevice(name, id)
{
    locked = true; // start locked
}

void DoorLock::lock()
{
    if (locked)
        throw DeviceStateException("Door is already locked!");
    locked = true;
}

void DoorLock::unlock()
{
    if (!locked)
        throw DeviceStateException("Door is already unlocked");

    locked = false;
}

void DoorLock::display() const
{
    cout << "Door [" << getName() << "] "
         << (locked ? "LOCKED" : "UNLOCKED") << endl;
}

bool DoorLock::getIsLocked() const {
    return locked;
}

void DoorLock::update()
{
    cout << "connecting the door lock security server" << endl;
}
