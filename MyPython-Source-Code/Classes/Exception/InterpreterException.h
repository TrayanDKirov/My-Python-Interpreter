#pragma once
#include <stdexcept>

class interpreter_exception : public std::runtime_error
{
public:
    interpreter_exception(const char* msg) : std::runtime_error(msg) { }
};