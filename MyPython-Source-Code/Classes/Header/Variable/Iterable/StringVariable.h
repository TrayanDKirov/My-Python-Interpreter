#pragma once
#include "Iterable.h"

class StringVariable : public Iterable
{
    string value = "";
    static const char BIG_QUOTE;
    static const char SMALL_QUOTE;

    static bool isValidString(const string& value);

public:
    StringVariable(const string& value);

    string toString() const override;

    ~StringVariable() override = default;
};
