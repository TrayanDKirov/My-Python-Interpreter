#pragma once
#include "Error.h"

class index_error : public error
{
    index_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    index_error(const char* msg) : error(("IndexError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw index_error((prefix + what()).c_str(), true);
    }
};