#pragma once
#include "Error.h"

class zero_division_error : public error
{
    zero_division_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    zero_division_error(const char* msg) : error(("ZeroDivisionError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw zero_division_error((prefix + what()).c_str(), true);
    }
};