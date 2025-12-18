#include "../../../Header/Interpreter/Operation/OperationFactory.h"

#include "../../../Exception/Error.h"
#include "../../../Exception/SyntaxError.h"
#include "../../../Header/Interpreter/MpySymbols.h"
#include "../../../Header/Interpreter/Operation/EvalOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/PrintOperation.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/BoolCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/FloatCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/IntCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/CastOperation/StringCastOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/InputOperation.h"
using std::vector;
using std::string;
using std::unique_ptr;

#include "../../../Header/Interpreter/Operation/Assignment.h"

int indexOf(const vector<string>& tokens, const string& toSearch, size_t start, size_t end) {
    for (size_t i = start; i < end && i < tokens.size(); i++) {
        if (tokens[i] == toSearch) {
            return i;
        }
    }

    return -1;
}

Operation* OperationFactory::createAssigment(const vector<string>& tokens, size_t start, size_t end) const {
    int index = indexOf(tokens, Assignment::ASSIGMENT_OPERATOR, start, end);
    if (index < start || index >= end) {
        return nullptr;
    }

    if (index != start+1) {
        //throw syntax_error(("valid syntax for assigment: " + Assignment::ASSIGMENT_SYNTAX).c_str());
        return nullptr;
    }

    return new Assignment(tokens[start],
        unique_ptr<Operation>(
            createLeave(tokens, index+1, end)));
}

vector<unique_ptr<Operation>> OperationFactory::parseArgs(const vector<string>& tokens,
    size_t start, size_t end) const
{
    vector<unique_ptr<Operation>> result;
    if (!MpySymbols::isStartBracket(tokens[start-1])
        || !MpySymbols::isEndBracket(tokens[end]))
        return result;

    size_t currStart = start;
    int bracketCounter = 0;
    bool ignoreCommas = false;
    for (size_t i = start; i < tokens.size(); i++) {
        if (MpySymbols::isStartBracket(tokens[i])) {
            ignoreCommas = true;
            bracketCounter++;
        } else if (MpySymbols::isEndBracket(tokens[i]))
            bracketCounter--;
        if (ignoreCommas && bracketCounter == 0)
            ignoreCommas = false;
        if (!ignoreCommas &&
            (MpySymbols::isCommaSep(tokens[i]) || i == tokens.size()-1 || i == end)) {
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

bool isTupleStart(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::startBracket;
}

Operation* OperationFactory::createLeave(const vector<string>& tokens, size_t start, size_t end) const {
    if (end-start == 1) {
        return new EvalOp(tokens[start]);
    }

    vector<unique_ptr<Operation>> args;
    if (!isTupleStart(tokens[start+1])) {
        throw error("Leave is not one token. ");
    }
    args = parseArgs(tokens, start+2, end-1);

    if (tokens[start] == PrintOperation::NAME) {
        return new PrintOperation(args);
    }
    if (tokens[start] == InputOperation::NAME) {
        return new InputOperation(args);
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
