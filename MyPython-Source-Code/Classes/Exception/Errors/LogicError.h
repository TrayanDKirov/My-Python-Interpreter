#pragma once
#include "Error.h"

class logic_error : public error
{
    logic_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    logic_error(const char* msg) : error(("LogicError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw logic_error((prefix + what()).c_str(), true);
    }
};