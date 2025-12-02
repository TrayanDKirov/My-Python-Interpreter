#pragma once
#include <memory>

#include "Variable.h"
#include "../Contex/Context.h"

class VariableFactory {
    const Context* context;

public:
    VariableFactory(const Context* context);

    std::unique_ptr<Variable> create(const std::string& value) const;
};