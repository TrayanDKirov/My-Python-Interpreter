#pragma once

#include "Call.h"
#include "Variable/Variable.h"

class return_call : public call
{    
public:
    Variable* result;
    
    return_call(const char* msg, Variable* result) : call(msg), result(result) { }
};
