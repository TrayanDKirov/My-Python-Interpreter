#include "../../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/GetElementOp.h"

#include "../../../../../Exception/TypeError.h"
#include "Variable/Iterable/ListVariable.h"
#include "Variable/Number/IntegerNumber.h"
using std::unique_ptr;

GetElementOp::GetElementOp(unique_ptr<Operation>& getListOp, unique_ptr<Operation>& getIndexOp)
    : getListOp(std::move(getListOp)), getIndexOp(std::move(getIndexOp)) { }

Variable* GetElementOp::execute(Context& contex) {
    Variable* listVar = getListOp->execute(contex);
    auto list = dynamic_cast<ListVariable*>(listVar);
    if (!list) {
        delete listVar;

        throw type_error("you can get element with index only on list variables");
    }
    
    Variable* indexVar = getIndexOp->execute(contex);
    auto index = dynamic_cast<IntegerNumber*>(indexVar);
    if (!index) {
        delete listVar;
        delete indexVar;

        throw type_error("index must be of type int");
    }
    
    Variable* element = (*list)[index->getValue()]->clone();
    delete listVar;
    delete indexVar;
    return element;
}

