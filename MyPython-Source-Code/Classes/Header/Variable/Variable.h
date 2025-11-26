#pragma once
#include <string>
using std::string;

class Variable {
    string name;
public:
    virtual string toString() const = 0;

    virtual ~Variable() = default;
};