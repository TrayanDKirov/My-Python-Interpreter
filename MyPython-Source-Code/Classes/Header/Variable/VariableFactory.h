#pragma once
#include "Variable.h"
#include "../Contex/Context.h"

class VariableFactory
{
    VariableFactory() = default;

public:

    Variable* create(const std::string& value) const;
    Variable* createByName(const std::string& value, Context& context) const;

    static std::string getTypeOfVariable(Variable* variable);

    static VariableFactory& getInstance();
};