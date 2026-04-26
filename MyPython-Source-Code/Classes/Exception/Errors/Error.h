#pragma once
#include <stdexcept>

class error : public std::runtime_error
{
public:
    error(const char* msg) : std::runtime_error(msg) { }
};
