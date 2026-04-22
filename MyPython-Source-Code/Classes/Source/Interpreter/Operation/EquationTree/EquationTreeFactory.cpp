#include "Interpreter/Operation/EquationTree/EquationTreeFactory.h"

#include "../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/LessOrEqualOperation.h"
#include "Interpreter/MpySymbols.h"
#include "Interpreter/Operation/OperationFactory.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/DivOperation.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/MinusOperation.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/MultOperation.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/PercentOperation.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/PlusOperation.h"
#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/PowerOperation.h"
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

BasicEqTree * EquationTreeFactory::createPr1(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    if (MpySymbols::isStartBracket(tokens[start]) && MpySymbols::isEndBracket(tokens[end-1]))
        return createPr8(tokens, start+1, end-1);

    return operationFactory->createLeave(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr2(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    for (int i = start; i < end && i < tokens.size(); i++) {
        if (MpySymbols::isStartBracket(tokens[i])) {
            i = endBracketIndexes[i];
            continue;
        }
        if (tokens[i] == PowerOperation::NAME)
        {
            return new PowerOperation(unique_ptr<BasicEqTree>(createPr4(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr3(tokens, i+1, end)));
        }
    }

    return createPr1(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr3(const std::vector<std::string> &tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }

        if (tokens[i] == MultOperation::NAME)
        {
            return new MultOperation(unique_ptr<BasicEqTree>(createPr4(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr3(tokens, i+1, end)));
        }
        if (tokens[i] == DivOperation::NAME)
        {
            return new DivOperation(unique_ptr<BasicEqTree>(createPr3(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr3(tokens, i+1, end)));
        }
        if (tokens[i] == PercentOperation::NAME) {
            return new PercentOperation(unique_ptr<BasicEqTree>(createPr3(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr3(tokens, i+1, end)));
        }
    }

    return createPr2(tokens, start, end);
}

BasicEqTree * EquationTreeFactory::createPr4(const std::vector<std::string> &tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }

        if (tokens[i] == PlusOperation::NAME)
        {
            return new PlusOperation(unique_ptr<BasicEqTree>(createPr4(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr4(tokens, i+1, end)));
        }
        if (tokens[i] == MinusOperation::NAME)
        {
            return new MinusOperation(unique_ptr<BasicEqTree>(createPr4(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr4(tokens, i+1, end)));
        }
    }

    return createPr3(tokens, start, end);
}

BasicEqTree * EquationTreeFactory::createPr5(const std::vector<std::string> &tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }

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

BasicEqTree * EquationTreeFactory::createPr6(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }
        if (tokens[i] == NotOperation::NAME)
        {
            return new NotOperation(unique_ptr<BasicEqTree>(nullptr),
                unique_ptr<BasicEqTree>(createPr6(tokens, i+1, end)));
        }
    }

    return createPr5(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr7(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }

        if (tokens[i] == AndOperation::NAME)
        {
            return new AndOperation(unique_ptr<BasicEqTree>(createPr7(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr7(tokens, i+1, end)));
        }
    }

    return createPr6(tokens, start, end);
}

BasicEqTree* EquationTreeFactory::createPr8(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    for (int i = end - 1; i >= start && i >= 0; i--)
    {
        if (MpySymbols::isEndBracket(tokens[i])) {
            i = startBracketIndexes[i];
            continue;
        }

        if (tokens[i] == OrOperation::NAME)
        {
            return new OrOperation(unique_ptr<BasicEqTree>(createPr8(tokens, start, i)),
                unique_ptr<BasicEqTree>(createPr8(tokens, i+1, end)));
        }
    }

    return createPr7(tokens, start, end);
}

void EquationTreeFactory::findEndBracket(const std::vector<std::string> &tokens, size_t startBracketIndex, size_t end)
{
    int bracketCounter = 0;
    for (size_t i = startBracketIndex; i < end; i++)
    {
        if (MpySymbols::isStartBracket(tokens[i]))
            bracketCounter++;
        else if (MpySymbols::isEndBracket(tokens[i]))
            bracketCounter--;

        if (bracketCounter == 0) {
            endBracketIndexes[startBracketIndex] = i;
            return;
        }
    }
}

void EquationTreeFactory::initBracketIndexes(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    for (size_t i = start; i < end && i < tokens.size(); i++)
    {
        if (MpySymbols::isStartBracket(tokens[i]))
            findEndBracket(tokens, i, end);
    }

    for (const auto& [key, value] : endBracketIndexes)
        startBracketIndexes[value] = key;
}

void EquationTreeFactory::clearFactory()
{
    startBracketIndexes.clear();
    endBracketIndexes.clear();
}

EquationTreeFactory::EquationTreeFactory(OperationFactory* operationFactory)
    : operationFactory(operationFactory) { }

BasicEqTree * EquationTreeFactory::create(const std::vector<std::string>& tokens, size_t start, size_t end)
{
    initBracketIndexes(tokens, start, end);

    BasicEqTree* result = createPr8(tokens, start, end);

    clearFactory();

    return result;
}
