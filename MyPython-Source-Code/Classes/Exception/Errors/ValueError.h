#pragma once
#include "Error.h"

class value_error : public error
{
public:
    value_error(const char* msg) : error(msg) { }
};