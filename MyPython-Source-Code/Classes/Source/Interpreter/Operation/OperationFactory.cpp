#include "../../../Header/Interpreter/Operation/OperationFactory.h"

#include <algorithm>
#include <bits/ranges_uninitialized.h>

#include "../../../Exception/OperationException.h"
#include "../../../Header/Variable/VariableFactory.h"
using namespace std;

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

    if (index != 1 || tokens.size() != 3) {
        throw operation_exception(Assignment::ASSIGMENT_SYNTAX.c_str());
    }

    ;

    return new Assignment(tokens[0], std::move(variableFactory->create(tokens[2])));
}

OperationFactory::OperationFactory(VariableFactory *variableFactory) : variableFactory(variableFactory) { }

Operation* OperationFactory::create(const std::vector<std::string> &tokens) const {
    Operation* result = searchForAssigment(tokens);

    if (result)
    {
       return result;
    }
    return nullptr;
}
