#pragma once
#include "Error.h"

class logic_error : public error
{
public:
    logic_error(const char* msg) : error(("LogicError: " + std::string(msg)).c_str())  { }
};