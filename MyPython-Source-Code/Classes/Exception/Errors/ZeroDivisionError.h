#pragma once
#include "Error.h"

class zero_division_error : public error
{
public:
    zero_division_error(const char* msg) : error(msg) { }
};