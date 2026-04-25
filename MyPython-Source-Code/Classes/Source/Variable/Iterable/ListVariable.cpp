#include "../../../Header/Variable/Iterable/ListVariable.h"

#include "../../../Exception/IndexError.h"
#include "Interpreter/MpySymbols.h"
#include "Variable/Iterable/StringVariable.h"

using std::vector;
using std::unique_ptr;
using std::string;

ListVariable::ListVariable(std::vector<std::unique_ptr<Variable>>& value)
    : value(std::move(value)) { }

string ListVariable::toString() const {
    string result = "";
    result.push_back(MpySymbols::sqStartBracket);
    
    for (size_t i = 0; i < value.size(); i++) {
        if (dynamic_cast<StringVariable*>(value[i].get()))
            result += "\"" + value[i]->toString() + "\"";
        else
            result += value[i]->toString();
        if (i != value.size() - 1) {
            result.push_back(MpySymbols::commaSep);
            result.push_back(' ');
        }
    }
    
    result.push_back(MpySymbols::sqEndBracket);

    return result;
}

Variable* ListVariable::operator[](int index) const {
    if (index < 0 || index >= value.size())
        throw index_error("list index out of range. ");

    return value[index]->clone();
}

std::unique_ptr<Variable> & ListVariable::operator[](int index) {
    if (index < 0 || index >= value.size())
        throw index_error("list index out of range. ");

    return value[index];
}

size_t ListVariable::size() const {
    return this->value.size();
}

Variable * ListVariable::clone() const {
    vector<unique_ptr<Variable>> newValue;

    for (size_t i = 0; i < value.size(); i++) {
        newValue.push_back(unique_ptr<Variable>(value[i]->clone()));
    }

    return new ListVariable(newValue);
}

