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
    int toInt() const;
    float toFloat() const;
    bool toBool() const;

    std::string getValue() const;
    void setValue(const std::string& value);

    char operator[](int index) const;
    char& operator[](int index);

    Variable* clone() const override;
    ~StringVariable() override = default;

    friend bool operator==(const StringVariable& left, const StringVariable& right);
};

