#pragma once

#include "Call.h"

class break_call : public call
{
public:
    break_call(const char* msg) : call(msg) { }
};
