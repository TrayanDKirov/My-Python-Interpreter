#include "../../Header/Contex/Scope.h"

#include "../../Exception/ScopeException/NotInScopeException.h"
using std::string;
using std::unique_ptr;

Scope::Scope(Scope* parent) : parent(parent) { }

Variable* Scope::get(const string &name) {
    auto iter = names.find(name);
    if (iter == names.end()) {
        return iter->second.get();
    }
    if (parent) {
        return parent->get(name);
    }

    throw not_in_scope_exception(name);
}

const Variable* Scope::get(const string& name) const {
    auto iter = names.find(name);
    if (iter != names.end()) {
        return iter->second.get();
    }
    if (parent) {
        return parent->get(name);
    }

    throw not_in_scope_exception(name);
}

bool Scope::contains(const string &name) const {
    auto iter = names.find(name);
    if (iter == names.end()) {
        return true;
    }
    if (parent) {
        return parent->contains(name);
    }

    return false;
}

bool Scope::assign(const string& name, unique_ptr<Variable> variable) {
    bool isFound = contains(name);
    names.insert_or_assign(name, std::move(variable));
    return isFound;
}

std::ostream& operator<<(std::ostream& os, const Scope& scope)
{
    os << "{\n";

    for (const auto& [name, varPtr] : scope.names) {
        os << "  " << name << ": ";
        if (varPtr)
            os << varPtr->toString();   // or operator<< if you define one
        else
            os << "<null>";
        os << "\n";
    }

    os << "}";
    return os;
}

