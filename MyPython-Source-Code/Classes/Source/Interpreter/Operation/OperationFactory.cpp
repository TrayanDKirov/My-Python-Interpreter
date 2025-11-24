#include "../../../Header/Interpreter/Operation/OperationFactory.h"

#include "../../../Header/Interpreter/Operation/Assignment.h"

Operation* OperationFactory::create(const std::vector<std::string> &tokens) const {
    return new Assignment();
}
