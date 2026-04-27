#pragma once
#include "Error.h"

class type_error : public error
{
    type_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    type_error(const char* msg) : error(("TypeError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw type_error((prefix + what()).c_str(), true);
    }
};
