#include "../../../../../Header/Interpreter/Operation/EquationTree/LeaveOperation/ListEvalOp.h"

#include "../../../../../Exception/TypeError.h"
#include "Variable/VoidVariable.h"
#include "Variable/Iterable/ListVariable.h"
using std::vector;
using std::unique_ptr;

ListEvalOp::ListEvalOp(std::vector<std::unique_ptr<Operation>>& elOps)
    : elOps(std::move(elOps)) { }

Variable* ListEvalOp::execute(Context& contex) {
    vector<unique_ptr<Variable>> elements;
    
    for (size_t i = 0; i < elOps.size(); i++) {
        Variable* var = elOps[i]->execute(contex);
        if (dynamic_cast<VoidVariable*>(var)) {
            delete var;
            
            throw type_error("cannot put operation without result in a list. ");
        }
        
        elements.push_back(unique_ptr<Variable>(var));
    }

    return new ListVariable(elements);
}


