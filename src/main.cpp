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
    //HELLo this is PArth
    // 1. Setup: Adding devices to the manager
    manager.addLightingDevice(new Light("Living Room Light", 1));
    manager.addEnvironmentDevice(new Thermostat("Main Thermostat", 2));
    manager.addSecurityDevice(new DoorLock("Front Door", 3));

    // 2. Initial check: Shows state of all devices
    cout << "-/- Initial System Audit -/-" << endl;
    manager.displayAll();

    // 3. Demo Interactions
    // Manual Interaction: Lighting (ID: 1)
    cout << "\n-//- Manual Interaction: Setting Light Brightness (ID: 1) -//-" << endl;
    try {
        // Find the device pointer
        SmartDevice* device = manager.findDevice(1);
        // Convert the generic pointer to a specific pointer
        Light* myLight = dynamic_cast<Light*>(device);

        if (myLight) {
            myLight->turnOn();
            myLight->setBrightness(85);
            cout << "Successfully set " << myLight->getName() << " to 85% brightness." << endl;
            
        }
    }
    catch (const InvalidValueException& e) {
        cout << "Custom Error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Standard Error: " << e.what() << endl;
    }

    // Manual Interaction: Security (ID: 2)
        cout << "\n-//- Interaction: Unlocking Front Door (ID: 3) -//-" << endl;
    try {
        SmartDevice* device = manager.findDevice(3);

        DoorLock* myDoor = dynamic_cast<DoorLock*>(device);

        if (myDoor) {
            myDoor->unlock();
            cout << "Successfully sent 'Unlock' command to: " << myDoor->getName() << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Manual Interaction: Environment (ID: 2)
    cout << "\n-//- Manual Interaction: Adjusting Thermostat (ID: 2) -//-" << endl;
    try {
        SmartDevice* device = manager.findDevice(2);
        
        // FIX
        Thermostat* myThermo = dynamic_cast<Thermostat*>(device);

        if (myThermo) {
            myThermo->setTemperature(80);
    
            cout << "Successfully adjusted " << myThermo->getName() << " to 80" << endl;
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
