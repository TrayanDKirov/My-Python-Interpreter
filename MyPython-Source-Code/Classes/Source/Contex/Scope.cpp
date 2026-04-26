#include "../../Header/Contex/Scope.h"

#include "../../Exception/Errors/TypeError.h"
#include "../../Exception/Errors/ValueError.h"
#include "../../Header/Variable/VariableFactory.h"
#include "Variable/Iterable/ListVariable.h"
#include "Variable/Iterable/StringVariable.h"
using std::string;
using std::unique_ptr;

Variable* Scope::getRealVar(const string& name) {
    auto iter = names.find(name);
    if (iter != names.end()) {
        return iter->second.get();
    }
    if (parent) {
        return parent->getRealVar(name);
    }

    throw value_error((name + " not defined in this scope").c_str());
}

Scope::Scope(Scope* parent) : parent(parent) { }

Variable* Scope::get(const string& name) const {
    auto iter = names.find(name);
    if (iter != names.end()) {
        return iter->second.get()->clone();
    }
    if (parent) {
        return parent->getRealVar(name)->clone();
    }

    throw value_error(("ValueError: " + name + " not defined in this scope").c_str());
}

Variable * Scope::getByIndex(const std::string& name, int index) const {
    Variable* var = get(name);
    if (auto iterableVar = dynamic_cast<IterableVariable*>(var)) {
        Variable* result = (*iterableVar)[index];
        delete var;
        
        return result;
    }
    
    delete var;
    throw type_error("can get indexed element only from iterable type");
}

bool Scope::assignByIndex(const std::string& name, int index, std::unique_ptr<Variable> variable) {
    Variable* var = getRealVar(name);
    if (auto listVar = dynamic_cast<ListVariable*>(var)) {
        (*listVar)[index] = std::move(variable);
        
        return true;
    }
    if (auto strVar = dynamic_cast<StringVariable*>(var)) {
        auto strToSetWith = dynamic_cast<StringVariable*>(variable.get());
        if (!strToSetWith) 
            throw type_error("you can set index only with variable of type str");
        
        string str = strToSetWith->getValue();
        if (str.size() > 1) 
            throw value_error("you can set index only with str with len 1 or 0");
        
        if (str.size() == 0) {
            string strToChange = strVar->getValue();
            for (size_t i = index; i < strToChange.size() - 1; i++) {
                strToChange[i] = strToChange[i+1];
            }
            strToChange.pop_back();

            strVar->setValue(strToChange);
            
            return true;
        }
        
        (*strVar)[index] = str[0];
        return true;
    }
    
    throw type_error("can set indexed element only from iterable type");
}

bool Scope::contains(const string &name) const {
    auto iter = names.find(name);
    if (iter != names.end()) {
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

bool Scope::assign(const std::string& name, const std::string& value) {
    VariableFactory variableFactory = VariableFactory::getInstance();
    return assign(name, unique_ptr<Variable>(variableFactory.create(value)));
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

