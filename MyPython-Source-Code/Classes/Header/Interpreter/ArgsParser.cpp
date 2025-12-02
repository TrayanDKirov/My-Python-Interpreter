#include "ArgsParser.h"

#include "../../Exception/InterpreterException.h"
#include "../Contex/Context.h"
using std::vector;
using std::string;
using std::unique_ptr;

ArgsParser::ArgsParser(const VariableFactory* variableFactory) : variableFactory(variableFactory) { }

vector<unique_ptr<Variable>> ArgsParser::parseArgs(const string& argsTuple) const
{
    vector<unique_ptr<Variable>> result;
    vector<string> args = tokenizer.tokenize(argsTuple);
    for (size_t i = 0; i < args.size(); i++)
    {
        string currArg = args[i];
        if (currArg[currArg.size()-1] == sep) {
            currArg = currArg.substr(0, currArg.size()-1);
        }
        else if (i < args.size() - 1 && args[i+1].size()==1 && args[i+1][0] == sep) {
            i++;
        }
        else if (i < args.size() - 1 && args[i+1].size()>1 && args[i+1][0] == sep) {
            args[i+1] = args[i+1].substr(1,args[i+1].size()-1);
        }
        else if (i != args.size() - 1) {
            throw interpreter_exception("arguments must be separated by ',' ");
        }


        result.push_back(variableFactory->create(currArg));
    }

    return result;
}
