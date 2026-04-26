#pragma once
#include "Error.h"

class syntax_error : public error
{
public:
    syntax_error(const char* msg) : error(msg) { }
};
