#include "Interpreter/Operation/EquationTree/LeaveOperation/ArgumentOperation/FunctionCallOperation.h"

#include "../../../../../../Exception/Errors/SyntaxError.h"
#include "../../../../../../Exception/InterpreterCalls/ReturnCall.h"
#include "Interpreter/Operation/EquationTree/LeaveOperation/EvalOp.h"
#include "Variable/NoneVariable.h"

using std::vector;
using std::string;
using std::unique_ptr;

void FunctionCallOperation::assignVars(Context& context, FunctionVariable* funcVar) {
    vector<unique_ptr<Variable>> args = getArgs(context);
    if (args.size() != funcVar->getVarNames().size())
        throw syntax_error("function arguments don't match");
    
    for (size_t i = 0; i < args.size(); i++) {
        context.getScope()
            .assign(funcVar->getVarNames()[i], std::move(args[i]));
    }
}

FunctionCallOperation::FunctionCallOperation(std::unique_ptr<EvalOp>&& opToGetFunc,
    vector<unique_ptr<Operation>>& args)
    : opToGetFunc(std::move(opToGetFunc)), ArgumentOperation(args) { }

Variable * FunctionCallOperation::execute(Context& context) {
    Variable* var = opToGetFunc->execute(context);
    FunctionVariable* funcVar = dynamic_cast<FunctionVariable*>(var);
    if (!funcVar) {
        delete var;

        throw syntax_error("you can call only a function");
    }
        
    Context myContext = context.getSubContext();
    assignVars(myContext, funcVar);

    try {
        funcVar->getBody().execute(myContext);
    } catch (return_call& rCall) {
        delete funcVar;
        
        return rCall.result;
    } catch (error& err) {
        string funcName = funcVar->getName();
        delete funcVar;

        err.rethrowWithMessage("In '" + funcName + "': ");
    }

    delete funcVar;
    
    return NoneVariable::getInstance().clone();
}


