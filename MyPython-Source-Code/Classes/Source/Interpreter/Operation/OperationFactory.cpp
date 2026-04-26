#include "Interpreter/Operation/OperationFactory.h"

#include <ranges>
#include <pstl/parallel_backend_serial.h>

#include "../../../Exception/Errors/Error.h"
#include "../../../Exception/Errors/SyntaxError.h"
#include "../../../Header/Interpreter/MpySymbols.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ListEvalOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/PrintOperation.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/BoolCastOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/FloatCastOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/IntCastOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/CastOperation/StringCastOp.h"
#include "../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/InputOperation.h"
#include "Interpreter/Operation/BreakOperation.h"
#include "Interpreter/Operation/ContinueOperation.h"
#include "Interpreter/Operation/ForOperation.h"
#include "Interpreter/Operation/IfOperation.h"
#include "Interpreter/Operation/PassOperation.h"
#include "Interpreter/Operation/WhileOperation.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FuncDefOperation.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FunctionCallOperation.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/ReturnOperation.h"

using std::vector;
using std::string;
using std::unique_ptr;

#include "../../../Header/Interpreter/Operation/Assignment.h"

OperationFactory::OperationFactory(vector<string>& lines)
    : lines(lines), eqTreeFactory(this), indentation(4) { }

OperationFactory::OperationFactory(vector<string>& lines, size_t indentation)
    : lines(lines), eqTreeFactory(this), indentation(indentation) { }

vector<unique_ptr<Operation>> OperationFactory::parseOpSequence(const vector<string>& tokens,
    size_t start, size_t end) {
    vector<unique_ptr<Operation>> result;
    if (start <= 0 || (!(MpySymbols::isStartBracket(tokens[start-1])
            && MpySymbols::isEndBracket(tokens[end]))
            && !(MpySymbols::isSqStartBracket(tokens[start-1])
            && MpySymbols::isSqEndBracket(tokens[end]))))
        return result;

    if (start >= end)
        return result;

    size_t currStart = start;
    int bracketCounter = 0;
    int sqBracketCounter = 0;
    bool ignoreCommas = false;
    for (size_t i = start; i < tokens.size(); i++) {
        if (MpySymbols::isStartBracket(tokens[i])) {
            ignoreCommas = true;
            bracketCounter++;
        } else if (MpySymbols::isEndBracket(tokens[i]))
            bracketCounter--;
        else if (MpySymbols::isSqStartBracket(tokens[i])) {
            ignoreCommas = true;
            sqBracketCounter++;
        } else if (MpySymbols::isSqEndBracket(tokens[i]))
            sqBracketCounter--;
        
        if (ignoreCommas && bracketCounter == 0 && sqBracketCounter == 0)
            ignoreCommas = false;
        if (!ignoreCommas &&
            (MpySymbols::isCommaSep(tokens[i]) || i == end || i == tokens.size()-1)) {
            result.push_back(unique_ptr<Operation>(create(tokens, currStart, i)));
            if (i == end || i == tokens.size()-1) {
                break;
            }
            currStart = i + 1;
        }
    }

    return result;
}

int indexOf(const vector<string>& tokens, const string& toSearch, size_t start, size_t end) {
    for (size_t i = start; i < end && i < tokens.size(); i++) {
        if (tokens[i] == toSearch) {
            return i;
        }
    }

    return -1;
}

bool isListStart(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::sqStartBracket;
}

bool isListEnd(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::sqEndBracket;
}

bool isList(const vector<string>& tokens, size_t start, size_t end) {
    return isListStart(tokens[start]) && isListEnd(tokens[end-1]);
}

bool isIndexList(const vector<string>& tokens, size_t start, size_t end) {
    return isList(tokens, start+1, end);
}

void assertListIndexCorrect(const vector<string>& tokens, size_t start, size_t index) {
    string commaSepStr = "";
    commaSepStr += MpySymbols::commaSep;
    int indexOfCommaSep = indexOf(tokens, commaSepStr, start+2, index-1);
    if (indexOfCommaSep >= start+2 && indexOfCommaSep < index-1)
        throw syntax_error("name [1, 3] is wrong syntax correct: name [1]");
}

Operation* OperationFactory::createAssigment(const vector<string>& tokens, size_t start, size_t end) {
    int index = indexOf(tokens, Assignment::ASSIGMENT_OPERATOR, start, end);
    if (index < start || index >= end) {
        return nullptr;
    }

    if (index == start+1) {
        return new Assignment(tokens[start],
        unique_ptr<Operation>(
            eqTreeFactory.create(tokens, index+1, end)));
    }

    if (isIndexList(tokens, start, index)) {
        assertListIndexCorrect(tokens, start, index);
        
        return new Assignment(tokens[start],
            unique_ptr<Operation>(
                eqTreeFactory.create(tokens, start+2, index-1)),
            unique_ptr<Operation>(
                eqTreeFactory.create(tokens, index+1, end)));
    }

    return nullptr;
}

bool OperationFactory::hasCorrectIndentation(size_t ind) {
    return ind % indentation == 0;
}

bool OperationFactory::hasCorrectIndentation(size_t ind, size_t currIndentation)
{
    return ind == currIndentation;
}

size_t getIndentation(const string& line)
{
    size_t index = 0;
    while (index < line.size() && line[index] == MpySymbols::whiteSpaceSep)
        index++;

    return index;
}

bool isPrefixIgnoreInd(const string& prefix, const string& line)
{
    size_t ind = getIndentation(line);
    for (size_t i = 0; i < prefix.size(); i++) {
        if (i+ind >= line.size() || prefix[i] != line[i+ind])
            return false;
    }

    return true;
}

IfOperation* OperationFactory::createIfBody(const std::vector<std::string>& tokens,
    size_t start, size_t end, size_t& currLineIndex) {
    unique_ptr<BasicEqTree> cond  = unique_ptr<BasicEqTree>(eqTreeFactory.create(tokens, start, end));

    OperationBody ifBody = readBody(currLineIndex);
    if (currLineIndex < lines.size() && isPrefixIgnoreInd(IfOperation::ELIF_NAME, lines[currLineIndex])) {
        vector<string> newLineTokens = tokenizer.tokenize(lines[currLineIndex]);

        unique_ptr<IfOperation> elif = unique_ptr<IfOperation>(createIfBody(newLineTokens,
            1, newLineTokens.size()-1, currLineIndex));

        return new IfOperation(cond, ifBody, elif);
    }

    if (currLineIndex < lines.size() && isPrefixIgnoreInd(IfOperation::ELSE_NAME, lines[currLineIndex]))
    {
        vector<string> elseTokens = tokenizer.tokenize(lines[currLineIndex]);

        if (elseTokens.size() == 2 && elseTokens[0] == IfOperation::ELSE_NAME && MpySymbols::isScopeStart(elseTokens[1])) {
            OperationBody elseBody = readBody(currLineIndex);

            currLineIndex--;
            return new IfOperation(cond, ifBody, elseBody);
        }
    }

    currLineIndex--;
    return new IfOperation(cond, ifBody);
}

Operation* OperationFactory::createIf(const std::vector<std::string>& tokens, size_t start, size_t end, size_t& currLineIndex)
{
    if (tokens[start] != IfOperation::IF_NAME || !MpySymbols::isScopeStart(tokens[end-1]))
        return nullptr;

    return createIfBody(tokens, start+1, end-1, currLineIndex);
}

Operation * OperationFactory::createWhile(const std::vector<std::string>& tokens, size_t start, size_t end,
    size_t& currLineIndex) {
    if (tokens[start] != WhileOperation::NAME || !MpySymbols::isScopeStart(tokens[end-1]))
        return nullptr;

    unique_ptr<BasicEqTree> cond  = unique_ptr<BasicEqTree>(eqTreeFactory.create(tokens, start+1, end-1));

    OperationBody body = readBody(currLineIndex);

    currLineIndex--;
    return new WhileOperation(cond, body);
}

Operation * OperationFactory::createFor(const std::vector<std::string> &tokens,
    size_t start, size_t end, size_t& currLineIndex) {
    if (end - start < 5 || tokens[start] != ForOperation::NAME || tokens[start+2] != ForOperation::IN
        || !MpySymbols::isScopeStart(tokens[end-1]))
        return nullptr;

    unique_ptr<Operation> opToGetIter(create(tokens, start+3, end-1));
    OperationBody body = readBody(currLineIndex);
    
    currLineIndex--;
    return new ForOperation(tokens[start+1], std::move(opToGetIter), body);
}

Operation * OperationFactory::createFunctionDef(const std::vector<std::string> &tokens,
    size_t start, size_t end, size_t &currLine) {
    if (end - start < 5 || tokens[start] != FuncDefOperation::NAME || !MpySymbols::isStartBracket(tokens[start+2])
        || !MpySymbols::isScopeStart(tokens[end-1]))
        return nullptr;

    vector<string> varNames;
    for (size_t i = start+3; i < end-1 && i < tokens.size(); i++) {
        if (MpySymbols::isEndBracket(tokens[i]))
            break;

        if (MpySymbols::isCommaSep(tokens[i])) {
            if ((i - start) % 2 == 1)
                throw syntax_error("comma separator not used correctly");
            continue;
        }
        
        varNames.push_back(tokens[i]);
    }

    OperationBody body = readBody(currLine);
    currLine--;

    return new FuncDefOperation(tokens[start+1], varNames, std::move(body));
}

ListEvalOp* OperationFactory::createList(const std::vector<std::string> &tokens, size_t start, size_t end) {
    vector<unique_ptr<Operation>> elOps;
    if (start <= 0 || !MpySymbols::isSqStartBracket(tokens[start-1])
            || !MpySymbols::isSqEndBracket(tokens[end]))
        return new ListEvalOp(elOps);

    elOps = std::move(parseOpSequence(tokens, start, end));

    return new ListEvalOp(elOps);
}

GetElementOp* OperationFactory::createGetElementOp(const std::vector<std::string>& tokens,
    size_t start, size_t end) {
    unique_ptr<Operation> getIndexOp(create(tokens, start+2, end-1));

    return new GetElementOp(tokens[start], getIndexOp);
}

OperationBody OperationFactory::readBody(size_t& currLineIndex)
{
    vector<unique_ptr<Operation>> operations;

    size_t currInd = getIndentation(lines[currLineIndex]);
    if (!hasCorrectIndentation(currInd))
        throw syntax_error("SyntaxError: indentation is not correct");

    currLineIndex++;
    while (currLineIndex < lines.size() && getIndentation(lines[currLineIndex]) == currInd + indentation)
    {
        operations.push_back(unique_ptr<Operation>(create(currLineIndex)));
    }

    if (currLineIndex < lines.size()) {
        size_t ind = getIndentation(lines[currLineIndex]);
        if (!hasCorrectIndentation(ind) || ind > currInd) {
            throw syntax_error("SyntaxError: indentation is not correct");
        }
    }

    return operations;
}

bool isTupleStart(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::startBracket;
}

bool isTupleEnd(const string& str) {
    return str.size() == 1 && str[0] == MpySymbols::endBracket;
}

bool isFunctionTuple(const vector<string>& tokens, size_t start, size_t end) {
    return isTupleStart(tokens[start+1]) && isTupleEnd(tokens[end-1]);
}

LeaveOperation* OperationFactory::createLeave(const vector<string>& tokens, size_t start, size_t end) {
    if (end-start == 1) {
        return new EvalOp(tokens[start]);
    }

    if (isList(tokens, start, end)) {
        return createList(tokens, start+1, end-1);
    }

    if (isIndexList(tokens, start, end)) {
        return createGetElementOp(tokens, start, end);
    }

    vector<unique_ptr<Operation>> args;
    if (!isFunctionTuple(tokens, start, end)) {
        throw error("Leave is not one token. ");
    }
    args = parseOpSequence(tokens, start+2, end-1);

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

    return new FunctionCallOperation(
        unique_ptr<EvalOp>(new EvalOp(tokens[start])),
        args);
}

Operation * OperationFactory::create(const std::vector<std::string> &tokens, size_t start, size_t end)
{
    Operation* result = createAssigment(tokens, start, end);
    if (result)
        return result;
    result = eqTreeFactory.create(tokens, start, end);
    if (result)
        return result;

    return nullptr;
}

Operation * OperationFactory::create(const std::vector<std::string> &tokens, size_t start, size_t end, size_t& currLine)
{
    
    if (tokens.empty() || tokens[start] == PassOperation::NAME)
        return new PassOperation();
    
    if (tokens[start] == ContinueOperation::NAME) {
        if (tokens.size() > 1)
            throw syntax_error((ContinueOperation::NAME + " must be alone on line").c_str());
        
        return new ContinueOperation();
    }
    if (tokens[start] == BreakOperation::NAME) {
        if (tokens.size() > 1)
            throw syntax_error((BreakOperation::NAME + " must be alone on line").c_str());
        
        return new BreakOperation();
    }
    if (tokens[start] == ReturnOperation::NAME) {
        
        return new ReturnOperation(
            unique_ptr<Operation>(create(tokens, start+1, end)));
    }

    Operation* result = createAssigment(tokens, start, end);
    if (result)
        return result;

    result = createIf(tokens, start, end, currLine);
    if (result)
        return result;

    result = createWhile(tokens, start, end, currLine);
    if (result)
        return result;

    result = createFor(tokens, start, end, currLine);
    if (result)
        return result;

    result = createFunctionDef(tokens, start, end, currLine);
    if (result)
        return result;

    result = createLeave(tokens, start, end);
    if (result)
        return result;

    return nullptr;
}

Operation * OperationFactory::create(size_t& currLineIndex) {
    vector<string> tokens = tokenizer.tokenize(lines[currLineIndex]);

    Operation* result = create(tokens, 0, tokens.size(), currLineIndex);
    currLineIndex++;

    return result;
}
