#include "../../Header/Contex/Context.h"

#include <iostream>

Context::Context() : is(std::cin), os(std::cout) { }

Context::Context(std::istream &is, std::ostream &os) : is(is), os(os) { }

Context::Context(Scope scope, std::istream &is, std::ostream &os)
    : scope(std::move(scope)), is(is), os(os) { }

Scope & Context::getScope()
{
    return this->scope;
}

const Scope & Context::getScope() const
{
    return this->scope;
}

std::istream & Context::getInputStream()
{
    return this->is;
}

std::ostream & Context::getOutputStream()
{
    return this->os;
}

Context Context::getSubContext() {
    return Context(Scope(&scope), is, os);
}

std::ostream& operator<<(std::ostream& os, const Context& contex)
{
    return os << contex.scope;
}
