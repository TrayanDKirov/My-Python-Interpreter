#pragma once
#include <memory>
#include <vector>

#include "IterableVariable.h"

class ListVariable : public IterableVariable
{
    std::vector<std::unique_ptr<Variable>> value;

public:
    ListVariable(std::vector<std::unique_ptr<Variable>>& value);

    std::string toString() const override;
    
    Variable* operator[](int index) const override;
    std::unique_ptr<Variable>& operator[](int index);

    size_t size() const override;

    Variable* clone() const override;
    ~ListVariable() override = default;
};