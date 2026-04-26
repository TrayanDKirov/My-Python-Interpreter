#pragma once
#include "../Variable.h"

class IterableVariable : public Variable {
public:
    virtual Variable* operator[](int index) const = 0;

    virtual size_t size() const = 0;
};
