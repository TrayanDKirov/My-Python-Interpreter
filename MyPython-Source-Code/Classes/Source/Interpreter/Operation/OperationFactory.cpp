#include "../../../Header/Interpreter/Operation/OperationFactory.h"

#include <algorithm>

#include "../../../Exception/OperationException.h"
#include "../../../Header/Interpreter/Operation/EvalOp.h"
#include "../../../Header/Interpreter/Operation/ArgumentOperation/PrintOp.h"
#include "../../../Header/Variable/VariableFactory.h"
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

Operation* OperationFactory::searchForAssigment(const vector<string>& tokens) const {
    int index = indexOf(tokens, Assignment::ASSIGMENT_OPERATOR);
    if (index == -1) {
        return nullptr;
    }

    if (index != 1) {
        throw operation_exception(Assignment::ASSIGMENT_SYNTAX.c_str());
    }

    return new Assignment(tokens[0],
        unique_ptr<Operation>(
            searchForSecondOperation(tokens, index+1, tokens.size())));
}

OperationFactory::OperationFactory(VariableFactory *variableFactory)
    : variableFactory(variableFactory), argsParser(variableFactory) { }

Operation* OperationFactory::searchForSecondOperation(const std::vector<std::string> &tokens, size_t start, size_t end) const {
    if (start == end-1) {
        return new EvalOp(tokens[start], variableFactory);
    }

    if (!ArgsParser::isArgsTuple(tokens[start+1])) {
        return nullptr;
    }

    if (tokens[start] == PrintOp::NAME) {
        auto args = argsParser.parseArgs(tokens[start+1].substr(1, tokens[start+1].size()-2));
        return new PrintOp(args);
    }

    return nullptr;
}

Operation* OperationFactory::create(const std::vector<std::string>& tokens) const
{
    Operation* result = searchForAssigment(tokens);
    if (result)
       return result;
    result = searchForSecondOperation(tokens, 0, tokens.size());
    if (result)
        return result;

    return nullptr;
}
