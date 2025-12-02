#pragma once
#include <stdexcept>

#include "InterpreterException.h"

class parsing_exception : public interpreter_exception {
public:
    parsing_exception(const char* msg) : interpreter_exception(msg) { }
};
