#pragma once
#include <memory>
#include <string>
#include <unordered_map>

#include "../Variable/Variable.h"

class Scope {
    std::unordered_map<std::string, std::unique_ptr<Variable>> names;
    Scope* parent = nullptr;

public:
    Scope() = default;
    Scope(Scope* parent);

    Scope(const Scope&) = delete;
    Scope& operator=(const Scope&) = delete;
    Scope(Scope&&) = default;
    Scope& operator=(Scope&&) = default;

    Variable* get(const std::string& name);
    const Variable* get(const std::string& name) const;

    bool contains(const std::string& name) const;
    bool assign(const std::string& name, std::unique_ptr<Variable> variable);
    bool assign(const std::string& name, const std::string& value);

    friend std::ostream& operator<<(std::ostream& os, const Scope& scope);
};
