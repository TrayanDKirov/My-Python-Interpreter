#pragma once

#include "Call.h"

class continue_call : public call
{
public:
    continue_call(const char* msg) : call(msg) { }
};
