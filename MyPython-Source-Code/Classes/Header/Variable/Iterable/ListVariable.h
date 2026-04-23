#pragma once
#include <memory>
#include <vector>

#include "Iterable.h"

class ListVariable : public Iterable
{
    std::vector<std::unique_ptr<Variable>> value;

public:
    ListVariable(std::vector<std::unique_ptr<Variable>>& value);

    std::string toString() const override;

    const std::unique_ptr<Variable>& operator[](size_t index) const; 
    std::unique_ptr<Variable>& operator[](size_t index);

    size_t size() const;

    Variable* clone() const override;
    ~ListVariable() override = default;
};