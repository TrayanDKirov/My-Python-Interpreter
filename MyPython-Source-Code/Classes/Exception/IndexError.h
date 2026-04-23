#pragma once
#include "Error.h"

class index_error : public error
{
public:
    index_error(const char* msg) : error(msg) { }
};