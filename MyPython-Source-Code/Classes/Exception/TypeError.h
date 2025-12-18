#pragma once
#include "Error.h"

class type_error : public error
{
public:
    type_error(const char* msg) : error(msg) { }
};
