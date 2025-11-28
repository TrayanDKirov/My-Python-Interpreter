#pragma once
#include <stdexcept>

class variable_exception : public std::runtime_error {
public:
    variable_exception(const std::string& value)
        : std::runtime_error(("unknown type of value - " + value).c_str()) { }

    variable_exception(const char* msg) : std::runtime_error(msg) { }
};