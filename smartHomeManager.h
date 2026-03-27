#ifndef SMARTHOMEMANAGER_H
#define SMARTHOMEMANAGER_H

#include <vector>
#include "SmartDevice.h"

using namespace std;

class SmartHomeManager
{
private:
    // Vectors to store devices
    // Note: Stores different types of devices in one container type. 
    //       Vector is best as it provides contiguous memory.
    vector<SmartDevice*> lighting;
    vector<SmartDevice*> security;
    vector<SmartDevice*> environment;

public:
    // Add devices to specific system
    void addLightingDevice(SmartDevice* device);
    void addSecurityDevice(SmartDevice* device);
    void addEnvironmentDevice(SmartDevice* device);

    // Display everything
    void displayAll() const;

    // Find device by ID
    SmartDevice* findDevice(int id) const;

    // Destructor
    ~SmartHomeManager();
    // Note: SmartHomeManager takes ownsership of the device pointers. 
    //       When destroyed, it must delete all devices to prevent memory leaks.
};

#endif