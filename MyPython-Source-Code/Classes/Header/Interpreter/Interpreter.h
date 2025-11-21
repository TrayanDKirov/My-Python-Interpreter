#include <string>

#include "Tokenizer.h"
#include "Operation/OperationFactory.h"

class Interpreter {
    std::string fileName = "";
    std::istream& is;
    std::ostream& os;

    Tokenizer tokenizer;
    OperationFactory operationFactory;

public:
    Interpreter(const std::string& fileName, std::istream& is, std::ostream& os);

    const std::string& getFileName() const;
    void setFileName(const std::string& fileName);

    void interpret() const;
};
