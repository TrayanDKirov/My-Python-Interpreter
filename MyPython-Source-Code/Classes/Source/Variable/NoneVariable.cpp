#include "../../Header/Variable/NoneVariable.h"
using std::string;

const string NoneVariable::NAME = "None";

string NoneVariable::toString() const
{
    return this->value;
}

Variable * NoneVariable::clone() const {
    return new NoneVariable(*this);
}