#include "../../../../Header/Interpreter/Operation/EquationTree/EquationTreeFactory.h"

#include "../../../../Header/Interpreter/Operation/OperationFactory.h"
#include "../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/AndOperation.h"
#include "../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"
using std::unique_ptr;

BasicEqTree* EquationTreeFactory::createPr7(const std::vector<std::string> &tokens, size_t start, size_t end) const
{
    return operationFactory->createLeave(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr8(const std::vector<std::string>& tokens, size_t start, size_t end) const
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (tokens[i] == AndOperation::NAME)
        {
            return new AndOperation(unique_ptr<BasicEqTree>(createPr8(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr8(tokens, i+1, end)));
        }
    }

    return createPr7(tokens, start, end);
}

EquationTreeFactory::EquationTreeFactory(OperationFactory* operationFactory)
    : operationFactory(operationFactory) { }

BasicEqTree * EquationTreeFactory::create(const std::vector<std::string>& tokens, size_t start, size_t end) const
{
    return createPr8(tokens, start, end);
}
