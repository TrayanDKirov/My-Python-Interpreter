#include "../../Header/Contex/Contex.h"

#include <iostream>

Contex::Contex() : is(std::cin), os(std::cout) { }

Contex::Contex(std::istream &is, std::ostream &os) : is(is), os(os) { }

Contex::Contex(Scope scope, std::istream &is, std::ostream &os)
    : scope(std::move(scope)), is(is), os(os) { }

Scope & Contex::getScope()
{
    return this->scope;
}

const Scope & Contex::getScope() const
{
    return this->scope;
}

std::istream & Contex::getInputStream()
{
    return this->is;
}

std::ostream & Contex::getOutputStream()
{
    return this->os;
}

std::ostream& operator<<(std::ostream& os, const Contex& contex)
{
    return os << contex.scope;
}
