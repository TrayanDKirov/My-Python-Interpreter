#pragma once
#include "Error.h"

class zero_division_error : public error
{
public:
    zero_division_error(const char* msg) : error(("ZeroDivisionError: " + std::string(msg)).c_str()) { }
};