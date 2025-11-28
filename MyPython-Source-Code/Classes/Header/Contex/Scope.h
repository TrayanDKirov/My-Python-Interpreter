#pragma once
#include <memory>
#include <string>
#include <unordered_map>
using std::unordered_map;
using std::unique_ptr;

#include "../Variable/Variable.h"

class Scope {
    unordered_map<string, unique_ptr<Variable>> names;
    Scope* parent = nullptr;

public:
    Scope() = default;
    Scope(Scope* parent);

    Scope(const Scope&) = delete;
    Scope& operator=(const Scope&) = delete;
    Scope(Scope&&) = default;
    Scope& operator=(Scope&&) = default;

    Variable* get(const string& name);
    const Variable* get(const string& name) const;

    bool contains(const string& name) const;
    bool assign(const string& name, unique_ptr<Variable> variable);

    friend std::ostream& operator<<(std::ostream& os, const Scope& scope);
};
