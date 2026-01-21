#include "Interpreter/Operation/EquationTree/EquationTreeFactory.h"

#include "../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/LessOrEqualOperation.h"
#include "Interpreter/Operation/OperationFactory.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/AndOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/BiggerOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/BiggerOrEqualOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/DifferentOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/EqualOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/LessOperation.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/NotOperation.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"
#include "Interpreter/Operation/EquationTree/BooleanEqTree/OrOperation.h"
using std::unique_ptr;

BasicEqTree * EquationTreeFactory::createPr4(const std::vector<std::string> &tokens, size_t start, size_t end) const
{
    return operationFactory->createLeave(tokens, start, end);
}

BasicEqTree * EquationTreeFactory::createPr5(const std::vector<std::string> &tokens, size_t start, size_t end) const
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (tokens[i] == EqualOperation::NAME)
        {
            return new EqualOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
        if (tokens[i] == DifferentOperation::NAME) {
            return new DifferentOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
        if (tokens[i] == LessOperation::NAME) {
            return new LessOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
        if (tokens[i] == BiggerOperation::NAME) {
            return new BiggerOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
        if (tokens[i] == LessOrEqualOperation::NAME) {
            return new LessOrEqualOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
        if (tokens[i] == BiggerOrEqualOperation::NAME) {
            return new BiggerOrEqualOperation(unique_ptr<BasicEqTree>(createPr5(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr5(tokens, i+1, end)));
        }
    }

    return createPr4(tokens, start, end);
}

BasicEqTree * EquationTreeFactory::createPr6(const std::vector<std::string>& tokens, size_t start, size_t end) const
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (tokens[i] == NotOperation::NAME)
        {
            return new NotOperation(unique_ptr<BasicEqTree>(nullptr),
                unique_ptr<BasicEqTree>(createPr6(tokens, i+1, end)));
        }
    }

    return createPr5(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr7(const std::vector<std::string>& tokens, size_t start, size_t end) const
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (tokens[i] == AndOperation::NAME)
        {
            return new AndOperation(unique_ptr<BasicEqTree>(createPr7(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr7(tokens, i+1, end)));
        }
    }

    return createPr6(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr8(const std::vector<std::string>& tokens, size_t start, size_t end) const
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (tokens[i] == OrOperation::NAME)
        {
            return new OrOperation(unique_ptr<BasicEqTree>(createPr8(tokens, start, i)),
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
