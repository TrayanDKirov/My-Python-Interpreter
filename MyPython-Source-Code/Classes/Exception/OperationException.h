#pragma once
#include "InterpreterException.h"

class operation_exception : public interpreter_exception {
public:
    operation_exception(const char* msg) : interpreter_exception(msg) { }
};
