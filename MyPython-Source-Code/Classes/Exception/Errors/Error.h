#pragma once
#include <stdexcept>
#include <string>

class error : public std::runtime_error
{
public:
    error(const char* msg) : std::runtime_error(msg) { }
    virtual void rethrowWithMessage(const std::string& prefix) const {
        throw error((prefix + what()).c_str());
    }
};
