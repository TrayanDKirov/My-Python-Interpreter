#include "../../../Header/Interpreter/Operation/OperationFactory.h"

#include <algorithm>

#include "../../../Exception/Error.h"
#include "../../../Exception/OperationException.h"
#include "../../../Exception/SyntaxError.h"
#include "../../../Header/Interpreter/MpySymbols.h"
#include "../../../Header/Interpreter/Operation/EvalOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/PrintOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/BoolCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/FloatCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/IntCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/StringCastOp.h"
using std::vector;
using std::string;
using std::unique_ptr;

#include "../../../Header/Interpreter/Operation/Assignment.h"

int indexOf(const vector<string>& tokens, const string& toSearch) {
    auto it = std::find(tokens.begin(), tokens.end(), toSearch);
    if (it != tokens.end())
        return static_cast<int>(std::distance(tokens.begin(), it));
    return -1;
}

Operation* OperationFactory::createAssigment(const vector<string>& tokens, size_t start, size_t end) const {
    int index = indexOf(tokens, Assignment::ASSIGMENT_OPERATOR);
    if (index < start || index >= end) {
        return nullptr;
    }

    if (index != start+1) {
        throw syntax_error(("valid syntax for assigment: " + Assignment::ASSIGMENT_SYNTAX).c_str());
    }

    return new Assignment(tokens[0],
        unique_ptr<Operation>(
            createLeave(tokens, index+1, tokens.size())));
}

vector<unique_ptr<Operation>> OperationFactory::parseArgs(const vector<string>& tokens,
    size_t start, size_t end) const
{
    vector<unique_ptr<Operation>> result;
    if (!MpySymbols::isStartBracket(tokens[start-1])
        || !MpySymbols::isEndBracket(tokens[end]))
        return result;

    size_t currStart = start;
    for (size_t i = start; i < tokens.size(); i++) {
        if (MpySymbols::isCommaSep(tokens[i]) || i == end || i == tokens.size()-1) {
            result.push_back(unique_ptr<Operation>(create(tokens, currStart,i)));
            if (i == end || i == tokens.size()-1) {
                break;
            }
            currStart = i + 1;
        }
    }

    return result;
}

Operation * OperationFactory::create(const std::vector<std::string> &tokens, size_t start, size_t end) const
{
    Operation* result = createAssigment(tokens, start, end);
    if (result)
        return result;
    result = createLeave(tokens, start, end);
    if (result)
        return result;

    return nullptr;
}

OperationFactory::OperationFactory(VariableFactory *variableFactory)
    : variableFactory(variableFactory) { }

bool isTupleStart(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::startBracket;
}

Operation* OperationFactory::createLeave(const vector<string>& tokens, size_t start, size_t end) const {
    if (end-start == 1) {
        return new EvalOp(tokens[start], variableFactory);
    }

    vector<unique_ptr<Operation>> args;
    if (!isTupleStart(tokens[start+1])) {
        throw error("Leave is not one token. ");
    }
    args = parseArgs(tokens, start+2, end-1);

    if (tokens[start] == PrintOp::NAME) {
        return new PrintOp(args);
    }
    if (tokens[start] == IntCastOp::NAME) {
        return new IntCastOp(args);
    }
    if (tokens[start] == FloatCastOp::NAME) {
        return new FloatCastOp(args);
    }
    if (tokens[start] == StringCastOp::NAME) {
        return new StringCastOp(args);
    }
    if (tokens[start] == BoolCastOp::NAME) {
        return new BoolCastOp(args);
    }

    return nullptr;
}

Operation* OperationFactory::create(const std::vector<std::string>& tokens) const
{
    return create(tokens, 0, tokens.size());
}
