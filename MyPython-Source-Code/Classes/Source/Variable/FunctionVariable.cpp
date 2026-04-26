#include "../../Header/Variable/FunctionVariable.h"

using std::vector;
using std::string;

const string FunctionVariable::DEF_FUNC_NAME = "def";

FunctionVariable::FunctionVariable(const string &name, const vector<string> &varNames,
    std::shared_ptr<OperationBody> body) : name(name), varNames(varNames),
    body(std::move(body)) { }

string FunctionVariable::toString() const {
    return "<function:" + name + ">";
}

string FunctionVariable::getName() const {
    return this->name;
}

const vector<string> & FunctionVariable::getVarNames() const {
    return this->varNames;
}

const OperationBody & FunctionVariable::getBody() const {
    return *body;
}

Variable * FunctionVariable::clone() const {
    return new FunctionVariable(*this);
}
