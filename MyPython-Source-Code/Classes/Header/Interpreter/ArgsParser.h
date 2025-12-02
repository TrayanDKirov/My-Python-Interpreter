#pragma once
#include <vector>

#include "Tokenizer.h"
#include "../Variable/Variable.h"
#include "../Variable/VariableFactory.h"


class ArgsParser
{
    Tokenizer tokenizer;
    char sep = ',';

    const VariableFactory* variableFactory;

public:
    ArgsParser(const VariableFactory* variableFactory);

    std::vector<std::unique_ptr<Variable>> parseArgs(const std::string& argsTuple) const;
};
