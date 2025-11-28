#pragma once
#include "Scope.h"

class Contex {
    Scope scope;
    std::istream& is;
    std::ostream& os;
public:
    Contex();
    Contex(std::istream& is, std::ostream& os);
    Contex(Scope scope, std::istream& is, std::ostream& os);

    Scope& getScope();
    const Scope& getScope() const;

    std::istream& getInputStream();
    std::ostream& getOutputStream();

    friend std::ostream& operator<<(std::ostream& os, const Contex& contex);
};
