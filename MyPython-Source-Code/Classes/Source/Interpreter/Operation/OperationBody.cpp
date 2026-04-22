#include "Interpreter/Operation/OperationBody.h"

OperationBody::OperationBody(std::vector<std::unique_ptr<Operation>>& operations)
    : operations(std::move(operations)) { }

void OperationBody::execute(Context &context) {
    for (size_t i = 0; i < operations.size(); i++)
    {
        Variable* var = operations[i]->execute(context);
        delete var;
    }
}

bool OperationBody::empty() const {
    return this->operations.empty();
}

