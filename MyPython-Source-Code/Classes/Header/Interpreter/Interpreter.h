#pragma once
#include "Tokenizer.h"
#include "Operation/OperationFactory.h"

#include <string>

#include "../Variable/VariableFactory.h"

class Interpreter {
    std::string fileName;
    Context context;
    OperationFactory operationFactory;
    std::vector<std::string> lines;

    void readLines(std::ifstream& inputFile);
    void readFile();

public:
    Interpreter(const std::string& fileName, std::istream& is, std::ostream& os);

    const std::string& getFileName() const;
    void setFileName(const std::string& fileName);

    void interpret();
    void interpret(Context& context);

    void printContex() const;
};
