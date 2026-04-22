#pragma once
#include <string>
#include <vector>

#include "IfOperation.h"
#include "Operation.h"
#include "OperationBody.h"
#include "EquationTree/EquationTreeFactory.h"
#include "EquationTree/LeaveOperation/LeaveOperation.h"
#include "Interpreter/Tokenizer.h"


class EvalOp;

class OperationFactory
{
    std::vector<std::string>& lines;

    EquationTreeFactory eqTreeFactory;
    Tokenizer tokenizer;
    size_t indentation;

    bool hasCorrectIndentation(size_t ind);
    bool hasCorrectIndentation(size_t ind, size_t currIndentation);

    std::vector<std::unique_ptr<Operation>> parseArgs(const std::vector<std::string>& tokens,
        size_t start, size_t end);

    Operation* createAssigment(const std::vector<std::string>& tokens, size_t start, size_t end);
    IfOperation* createIfBody(const std::vector<std::string>& tokens, size_t start, size_t end, size_t& currLine);
    Operation* createIf(const std::vector<std::string>& tokens, size_t start, size_t end, size_t& currLine);
    Operation* createWhile(const std::vector<std::string>& tokens, size_t start, size_t end, size_t& currLine);

    OperationBody readBody(size_t& currLine);

    Operation* create(const std::vector<std::string>& tokens, size_t start, size_t end);
    Operation* create(const std::vector<std::string>& tokens, size_t start, size_t end, size_t& currLine);

public:

    explicit OperationFactory(std::vector<std::string>& lines);
    OperationFactory(std::vector<std::string>& lines, size_t indentation);

    LeaveOperation* createLeave(const std::vector<std::string>& tokens,
        size_t start, size_t end);

    Operation* create(size_t& currLineIndex);
};
