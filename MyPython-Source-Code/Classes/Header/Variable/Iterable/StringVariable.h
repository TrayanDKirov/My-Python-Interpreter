#pragma once
#include "IterableVariable.h"

class StringVariable : public IterableVariable
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

    Variable* operator[](int index) const override;
    char& operator[](int index);

    size_t size() const override;

    Variable* clone() const override;
    ~StringVariable() override = default;

    friend StringVariable operator+(const StringVariable& left, const StringVariable& right);
    friend bool operator==(const StringVariable& left, const StringVariable& right);
};

