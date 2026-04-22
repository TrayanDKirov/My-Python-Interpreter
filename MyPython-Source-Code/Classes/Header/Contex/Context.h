#pragma once
#include "Scope.h"

class Context {
    Scope scope;
    std::istream& is;
    std::ostream& os;
public:
    Context();
    Context(std::istream& is, std::ostream& os);
    Context(Scope scope, std::istream& is, std::ostream& os);

    Scope& getScope();
    const Scope& getScope() const;

    std::istream& getInputStream();
    std::ostream& getOutputStream();

    Context getSubContext();

    friend std::ostream& operator<<(std::ostream& os, const Context& contex);
};
