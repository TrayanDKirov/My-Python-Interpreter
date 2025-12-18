#include "../../Header/Variable/VoidVariable.h"

std::string VoidVariable::toString() const {
    return "void";
}

Variable* VoidVariable::clone() const {
    return new VoidVariable(*this);
}
