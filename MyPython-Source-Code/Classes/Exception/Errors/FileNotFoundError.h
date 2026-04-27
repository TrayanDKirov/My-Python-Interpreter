#pragma once
#include "Error.h"

class file_not_found_error : public error
{
    file_not_found_error(const char* fullMsg, bool) : error(fullMsg) { }
public:
    file_not_found_error(const char* msg) : error(("FileNotFoundError: " + std::string(msg)).c_str()) { }
    void rethrowWithMessage(const std::string& prefix) const override {
        throw file_not_found_error((prefix + what()).c_str(), true);
    }
};