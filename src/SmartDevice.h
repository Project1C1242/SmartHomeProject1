#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
using namespace std;

class SmartDevice
{
protected:
    string name;
    int id;

public:
    // Constructor
    // name: Name of the device | id: ID of the device
    // Note: This assigns a name and ID to every device, avoiding duplication
    SmartDevice(string name, int id);

    // Virtual functions
    // Note: Force derived classes to implement their own behavior
    virtual void display() const = 0;
    virtual void update() = 0;

    // Getters
    // Note: Return private data, no direct access to variables
    int getID() const;
    string getName() const;

    // Destructor
    // Note: Ensures proper destruction via base pointer. 
    //       (Without virtual destructor, only part of the object would be destroyed, leading to resource leaks)
    virtual ~SmartDevice() {}
};

#endif