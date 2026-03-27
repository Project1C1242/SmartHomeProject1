# Smart Home Device Manager

## Overview

This program emulates a basic smart home system using object-oriented programming in C++. Different devices are created and managed through a central manager.

-///-

## Design

### SmartDevice (Base Class)

* Acts as the parent class for all devices
* Stores common data like name and ID
* Defines:

  * `display()` → show device state
  * `update()`  → change device state

-///-

### Switchable (Interface)

* Used for devices that can be turned on/off
* Provides:

  * `turnOn()`
  * `turnOff()`
* Implemented by:

  * Light
  * DoorLock

-///-

### Light

/ Inherits from `SmartDevice` and `Switchable`
* Has:

  * ON/OFF state
  * Brightness level
* Can be turned on/off and adjusted

-///-

### DoorLock

* Inherits from `SmartDevice` and `Switchable`
* Uses:

  * ON = Locked
  * OFF = Unlocked

-///-

### Thermostat

* Inherits from `SmartDevice` and `Iadjustable`
* Uses:

  * Temperature
* Can be adjusted

-///-

### SmartHomeManager

* Stores all devices in a list
* Handles:

  * Adding devices
  * Displaying all devices
  * Updating all devices
* Uses polymorphism to treat all devices the same

-///-

## Notes

* `Switchable` is implemented but not used for group control yet.
* Devices are stored using base class pointers (SmartDevice*).
* Memory is cleaned up in the manager destructor.
* Custom exceptions are implemented but not used yet.