#include "TestArgsParser.h"

#include <iostream>

#include "../Classes/Header/Interpreter/ArgsParser.h"


void TestArgsParser::test1() {
    Context context;
    VariableFactory varFactory(&context);
    ArgsParser argsParser(&varFactory);
    context.getScope().assign("x", varFactory.create("124"));
    context.getScope().assign("y", varFactory.create("'string'"));
    context.getScope().assign("z", varFactory.create("True"));

    std::string t = "x , y   , 3.14, 0    ,False, z";
    auto args = argsParser.parseArgs(t);
    std::cout << t << std::endl;
    for (size_t i = 0; i < args.size(); i++) {
        std::cout << args[i].get()->toString() << ", ";
    }
}
