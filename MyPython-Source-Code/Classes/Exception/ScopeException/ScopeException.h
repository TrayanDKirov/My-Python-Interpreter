#pragma once
#include "../OperationException.h"

class scope_exception : public operation_exception {
public:
    scope_exception(const char* msg) : operation_exception(msg) { }
};