#pragma once
#include <stdexcept>

#include "InterpreterException.h"

class variable_exception : public interpreter_exception {
public:
    variable_exception(const std::string& value)
        : interpreter_exception(("unknown type of value - " + value).c_str()) { }

    variable_exception(const char* msg) : interpreter_exception(msg) { }
};
