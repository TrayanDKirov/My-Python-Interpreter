#pragma once
#include "Error.h"

class value_error : public error
{
    value_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    value_error(const char* msg) : error(("ValueError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw value_error((prefix + what()).c_str(), true);
    }
};