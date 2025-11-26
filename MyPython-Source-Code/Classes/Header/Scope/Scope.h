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
    Scope(Scope* parent);

    Variable* get(const string& name);
    const Variable* get(const string& name) const;

    bool contains(const string& name) const;
    bool assign(const string& name, unique_ptr<Variable> variable);
};
