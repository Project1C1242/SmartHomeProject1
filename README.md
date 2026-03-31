# Smart Home Device Manager

## Overview

This program emulates a basic smart home system using object-oriented programming in C++. Different devices are created and managed through a central manager.

Design Architecture: Smart Home Simulation
1. SmartDevice (Abstract Base Class)
This class serves as the foundational blueprint for the entire ecosystem. By defining a common ancestor, the system ensures that every piece of hardware adheres to a universal standard.

Encapsulated State: It centralizes shared attributes, specifically the device's name (string) and id (integer). By storing these as protected or private members, it prevents external modification while allowing derived classes to inherit this core identity.

Enforced Abstraction: It utilizes pure virtual functions (e.g., virtual void display() const = 0; and virtual void update() = 0;). This makes SmartDevice an abstract class, meaning it cannot be instantiated directly. Instead, it forces a contract: any specific device created from this blueprint must provide its own unique logic for displaying its status and updating its state.

Memory Safety: It includes a virtual destructor to ensure that when a derived object is deleted via a base class pointer, the derived class's destructor is called first, preventing resource leaks.

2. Switchable (Interface)
This class acts as an interface, adhering to the Interface Segregation Principle. Not all smart devices simply turn on or off (e.g., a thermostat), so this behavior is kept separate from the base SmartDevice class.

Behavioral Contract: It contains only pure virtual functions, specifically turnOn() and turnOff().

Multiple Inheritance: Classes that require binary power states can inherit from both SmartDevice (for core identity) and Switchable (for power functionality), keeping the class hierarchy modular and strictly categorized.

3. Concrete Devices (Derived Classes)
These are the fully implemented, instantiable classes that represent the physical hardware in the simulation. They inherit from SmartDevice and provide the specific logic for the pure virtual functions.

Light: * Inheritance: Uses multiple inheritance, extending both SmartDevice and Switchable.

State Management: Tracks two internal attributes: an ON/OFF boolean state and a brightness integer level.

Behavior: Implements the required turnOn() and turnOff() methods, alongside a setter for brightness that likely checks for valid ranges (e.g., 0-100%).

DoorLock: * Inheritance: Inherits solely from SmartDevice.

State Management: Tracks its secure state (e.g., an isLocked boolean).

Behavior: Implements highly specific domain methods: lock() and unlock(). It overrides display() to output its current security status rather than a power state.

Thermostat: * Inheritance: Inherits solely from SmartDevice.

State Management: Tracks a target or current temperature value.

Encapsulation: Protects the temperature variable by forcing adjustments through a setter method (e.g., setTemperature(int)). This setter contains logic to bound the temperature within realistic, safe limits (e.g., 50°F to 90°F), rejecting invalid inputs.

4. SmartHomeManager (The Central Hub)
This class acts as the orchestrator for the entire system, demonstrating the power of OOP relationships and dynamic memory.

Polymorphic Storage: Instead of maintaining separate lists for lights, locks, and thermostats, it stores all devices in generic containers (like std::vector) using base class pointers (SmartDevice*).

Runtime Polymorphism (Dynamic Binding): When iterating through the system to update statuses, the manager simply calls device->display() on every pointer. Because display() is virtual, the program uses the vtable to dynamically look up and execute the correct, specific method for that object at runtime (e.g., it knows to print brightness for a Light, and temperature for a Thermostat) without the Manager needing to know the device's concrete type.

Resource Acquisition Is Initialization (RAII): Since devices are dynamically allocated on the heap (using the new keyword), the Manager takes ownership of their lifecycles. Its destructor loops through all storage vectors and explicitly calls delete on every pointer, ensuring safe memory management and zero memory leaks upon shutdown.

5. Error Handling Architecture
The system abandons traditional error codes in favor of a robust, modern C++ exception-handling design. By inheriting from the standard <exception> library, the program can throw and catch highly specific, descriptive errors.

InvalidValueException: Triggered during state mutation when an argument falls outside acceptable physical bounds (e.g., attempting to set the Thermostat to 150 degrees, or Light brightness to 110%).

DeviceStateException: Triggered when a method call contradicts the current physical reality of the device (e.g., calling lock() on a DoorLock that is already secured, or turnOn() on a Light that is already powered up).

DeviceNotFoundException: Triggered by the SmartHomeManager if a user or system process attempts to query, update, or delete a hardware unit using an id that does not exist in the active registry.
