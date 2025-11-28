#pragma once
#include <memory>

#include "Variable.h"
using std::unique_ptr;

class VariableFactory {
    VariableFactory() = default;
    VariableFactory(const VariableFactory&) = delete;
    VariableFactory& operator=(const VariableFactory&) = delete;

public:
    unique_ptr<Variable> create(const string& value) const;

    static VariableFactory& getInstance();
};