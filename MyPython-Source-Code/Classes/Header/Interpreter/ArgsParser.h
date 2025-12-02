#pragma once
#include <algorithm>
#include <vector>

#include "Tokenizer.h"
#include "../Variable/Variable.h"
#include "../Variable/VariableFactory.h"


class ArgsParser
{
    Tokenizer tokenizer;

    const VariableFactory* variableFactory;

public:
    ArgsParser(const VariableFactory* variableFactory);

    std::vector<std::unique_ptr<Variable>> parseArgs(std::string argsTuple) const;

    static bool isArgsTuple(const std::string& str);
};
