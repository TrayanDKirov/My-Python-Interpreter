#pragma once
#include <stdexcept>

class call : public std::runtime_error
{
public:
    call(const char* msg) : std::runtime_error(msg) { }
};
