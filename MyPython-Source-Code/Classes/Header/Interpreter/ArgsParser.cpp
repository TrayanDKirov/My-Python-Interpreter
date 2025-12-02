#include "ArgsParser.h"

#include "../../Exception/InterpreterException.h"
#include "../Contex/Context.h"
using std::vector;
using std::string;
using std::unique_ptr;

ArgsParser::ArgsParser(const VariableFactory* variableFactory) : variableFactory(variableFactory) { }

static void replaceChars(string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ',') {
            str[i] = ' ';
        }
    }
}

vector<unique_ptr<Variable>> ArgsParser::parseArgs(string argsTuple) const
{
    vector<unique_ptr<Variable>> result;
    replaceChars(argsTuple);
    vector<string> args = tokenizer.tokenize(argsTuple);
    for (size_t i = 0; i < args.size(); i++)
    {
        result.push_back(variableFactory->create(args[i]));
    }

    return result;
}

bool ArgsParser::isArgsTuple(const std::string &str)
{
    return str[0] == '(' && str[str.size()-1] == ')';
}
