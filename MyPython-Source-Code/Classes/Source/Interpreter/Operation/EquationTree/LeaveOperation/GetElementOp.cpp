#include "../../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/GetElementOp.h"

#include "../../../../../Exception/Errors/TypeError.h"
#include "Variable/Iterable/ListVariable.h"
#include "Variable/Number/IntegerNumber.h"
using std::unique_ptr;
using std::string;

GetElementOp::GetElementOp(const string& iterableName, unique_ptr<Operation>& getIndexOp)
    : iterableName(iterableName), getIndexOp(std::move(getIndexOp)) { }

Variable* GetElementOp::execute(Context& contex) {
    Variable* indexVar = getIndexOp->execute(contex);
    auto index = dynamic_cast<IntegerNumber*>(indexVar);
    if (!index) {
        delete indexVar;

        throw type_error("index must be of type int");
    }
    
    Variable* element = contex.getScope().getByIndex(iterableName, index->getValue());
    
    delete indexVar;
    return element;
}

