#pragma once
#include "Variable.h"
#include "../Contex/Context.h"

class VariableFactory {
    const Context* context;

public:
    VariableFactory(const Context* context);

    Variable* create(const std::string& value) const;
};