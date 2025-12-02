#include "../../Header/Variable/NoneVariable.h"
using std::string;

string NoneVariable::toString() const
{
    return this->value;
}

Variable * NoneVariable::clone() const {
    return new NoneVariable(*this);
}