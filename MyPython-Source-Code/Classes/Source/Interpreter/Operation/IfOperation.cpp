#include "Interpreter/Operation/IfOperation.h"

#include "../../../Exception/ValueError.h"
#include "Variable/BoolVariable.h"
#include "Variable/VoidVariable.h"
using std::string;
using std::unique_ptr;

const string IfOperation::IF_NAME = "if";
const string IfOperation::ELSE_NAME = "else";
const string IfOperation::ELIF_NAME = "elif";


IfOperation::IfOperation(std::unique_ptr<BasicEqTree>& condition, OperationBody& ifBody)
    : condition(std::move(condition)), ifBody(std::move(ifBody))
{
    this->hasElse = false;
    this->hasElif = false;
}

IfOperation::IfOperation(unique_ptr<BasicEqTree>& condition,
                         OperationBody& ifBody, OperationBody& elseBody)
    : condition(std::move(condition)), ifBody(std::move(ifBody)),
    elseBody(std::move(elseBody))
{
    this->hasElse = true;
    this->hasElif = false;
}

IfOperation::IfOperation(std::unique_ptr<BasicEqTree>& condition,
    OperationBody& ifBody, unique_ptr<IfOperation>& elif)
    : condition(std::move(condition)), ifBody(std::move(ifBody)),
    elif(std::move(elif))
{
    this->hasElse = false;
    this->hasElif = true;
}

Variable * IfOperation::execute(Context& contex) {
    Variable* condResult = condition->execute(contex);
    BoolVariable* cond = dynamic_cast<BoolVariable*>(condResult);
    if (!cond) {
        throw value_error("ValueError: condition in if should return a bool value");
    }

    if (cond->getValue()) {
        ifBody.execute(contex);
    }
    else if (hasElif) {
        delete elif->execute(contex);
    }
    else if (hasElse) {
        elseBody.execute(contex);
    }

    delete condResult;

    return VoidVariable::getInstance().clone();
}
