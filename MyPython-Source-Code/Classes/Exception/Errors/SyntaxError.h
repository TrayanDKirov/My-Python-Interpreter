#pragma once
#include "Error.h"

class syntax_error : public error
{
    syntax_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    syntax_error(const char* msg) : error(("SyntaxError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw syntax_error((prefix + what()).c_str(), true);
    }
};
