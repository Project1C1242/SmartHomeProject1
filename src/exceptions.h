#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

// Value Errors
class InvalidValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Value provided outside of expected range.";
    }
};

// State Errors
class DeviceStateException : public std::exception {
private:
    const char* message;
public:
    // Pass custom message to exception
    DeviceStateException(const char* msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message;
    }
};

// Connection Errors
class DeviceNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Device ID not found.";
    }
};

#endif
