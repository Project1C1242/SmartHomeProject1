#include <iostream>
#include <vector>
#include "SmartHomeManager.h"
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "Exceptions.h"

using namespace std;

int main()
{
    SmartHomeManager manager;
    // 1. Setup: Adding devices to the manager
    manager.addLightingDevice(new Light("Living Room Light", 1));
    manager.addEnvironmentDevice(new Thermostat("Main Thermostat", 2));
    manager.addSecurityDevice(new DoorLock("Front Door", 3));

    // 2. Initial check: Shows state of all devices
    cout << "\n-/- Initial System Audit -/-" << endl;
    manager.displayAll();

    // 3. Demo Interactions
    cout << "\n-//- Demo Interactions -//-" << endl;
    // Manual Interaction: Lighting (ID: 1)
    cout << "\n/!/ Manual Interaction: Light Brightness (ID: 1) " << endl;
    try {
        // Find the device pointer
        SmartDevice* device = manager.findDevice(1);
        // Convert the generic pointer to a specific pointer
        Light* myLight = dynamic_cast<Light*>(device);

        if (myLight) {
            int targetBrightness = 85; 
                myLight->turnOn();
                myLight->setBrightness(targetBrightness);
            cout << "Successfully set " << myLight->getName() << " to " << myLight->getBrightness() << "% brightness." << endl;
        }
    }
    catch (const InvalidValueException& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const DeviceStateException& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Manual Interaction: Security (ID: 3)
        cout << "\n/!/ Interaction: Front Door (ID: 3)" << endl;
    try {
        SmartDevice* device = manager.findDevice(3);

        DoorLock* myDoor = dynamic_cast<DoorLock*>(device);

        if (myDoor) {
            myDoor->unlock();
            cout << "Status Update: " << myDoor->getName() << " is now " << (myDoor->getIsLocked() ? "LOCKED" : "UNLOCKED") << "." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Manual Interaction: Environment (ID: 2)
    cout << "\n/!/ Manual Interaction: Adjusting Thermostat (ID: 2) " << endl;
    try {
        SmartDevice* device = manager.findDevice(2);
        
        Thermostat* myThermo = dynamic_cast<Thermostat*>(device);

        if (myThermo) {
            int targetTemp = 80;
            myThermo->setTemperature(targetTemp);
    
            cout << "Successfully adjusted " << myThermo->getName() << " to " << myThermo->getTemperature() << " degrees." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // 4. Final Audit: Verify changes made to system
    cout << "\n-///- Final System Audit -///-" << endl;
    manager.displayAll();

    return 0;
}
