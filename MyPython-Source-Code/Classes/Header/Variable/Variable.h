#pragma once
#include <string>

class Variable {
    std::string name;
public:
    virtual std::string toString() const = 0;

    virtual Variable* clone() const = 0;
    virtual ~Variable() = default;
};