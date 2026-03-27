#include <iostream>
#include "DoorLock.h"
#include "Exceptions.h"

using namespace std;

DoorLock::DoorLock(string name, int id) : SmartDevice(name, id)
{
    locked = true; // start locked
}

void DoorLock::setLocked(bool locked)
{
    this->locked = locked;
}

void DoorLock::lock()
{
    if (locked)
        throw runtime_error("Door is already locked");

    locked = true;
}

void DoorLock::unlock()
{
    if (!locked)
        throw runtime_error("Door is already unlocked");

    locked = false;
}

void DoorLock::display() const
{
    cout << "Door [" << getName() << "] "
         << (locked ? "LOCKED" : "UNLOCKED") << endl;
}

void DoorLock::update()
{
}

// hello
