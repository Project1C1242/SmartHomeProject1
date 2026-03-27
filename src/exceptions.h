#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class InvalidValueException : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid value provided";
    }
};

#endif