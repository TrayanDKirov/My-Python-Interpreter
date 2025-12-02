#pragma once
#include "Iterable.h"

class StringVariable : public Iterable
{
    std::string value = "";
    static const char BIG_QUOTE;
    static const char SMALL_QUOTE;

    static bool isValidString(const std::string& value);

public:
    StringVariable(const std::string& value);

    std::string toString() const override;

    Variable* clone() const override;
    ~StringVariable() override = default;
};
