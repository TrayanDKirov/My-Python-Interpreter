#include <iostream>
#include <sstream>
#include <string>
#include "Classes/Header/Interpreter/Interpreter.h"

struct TestCase {
    std::string fileName;
    std::string expected;
};

void runTest(const TestCase& test) {
    std::ostringstream actual;
    Interpreter interpreter(test.fileName, std::cin, actual);
    interpreter.interpret();

    std::cout << "=== " << test.fileName << " ===\n";
    std::cout << "Expected:\n" << test.expected;
    std::cout << "Actual:\n"   << actual.str();
    std::cout << (actual.str() == test.expected ? "PASS" : "FAIL") << "\n\n";
}

void runTests() {
    TestCase tests[] = {
        { "tests/arithmetic.mpy",  "8\n2\n15\n2\n125\n1.666667\n" },
        { "tests/comparison.mpy",  "False\nTrue\nTrue\nFalse\nTrue\nFalse\nTrue\nFalse\n" },
        { "tests/boolean.mpy",     "True\nFalse\nTrue\nFalse\nFalse\nTrue\n" },
        { "tests/conditionals.mpy","big\nmedium\nnot positive\n" },
        { "tests/casting.mpy",     "42\n1\n3.140000\nFalse\nTrue\n100\nTrue\nhello\n" },
        { "tests/while.mpy",       "0\n1\n2\n3\n4\n15\n" },
        { "tests/list.mpy",        "[1, 2, 3, 4]\n1\n4\n[1, 10, 3, 4]\n6\n3\n99\n" }
    };

    for (const auto& test : tests) {
        runTest(test);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: mpy -run-tests | <file.mpy>\n";
        return 1;
    }

    std::string arg = argv[1];

    if (arg == "-run-tests") {
        runTests();
        return 0;
    }

    Interpreter interpreter(arg, std::cin, std::cout);
    interpreter.interpret();

    return 0;
}