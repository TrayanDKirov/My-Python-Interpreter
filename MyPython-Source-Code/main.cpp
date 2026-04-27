#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Classes/Header/Interpreter/Interpreter.h"

namespace fs = std::filesystem;

struct TestCase {
    std::string fileName;
    std::string expected;
};

static std::string getTestName(const std::string& filePath) {
    std::string name = filePath;
    
    const std::string prefix = "tests/";
    size_t pos = name.find(prefix);
    if (pos != std::string::npos)
        name = name.substr(pos + prefix.size());
    
    size_t dot = name.rfind('.');
    if (dot != std::string::npos)
        name = name.substr(0, dot);
    
    for (char& c : name)
        if (c == '/' || c == '\\')
            c = '_';
    return name;
}

static bool runTest(const TestCase& test) {
    std::ifstream srcFile(test.fileName);
    std::ostringstream srcContent;
    srcContent << srcFile.rdbuf();

    std::ostringstream actual;
    Interpreter interpreter(test.fileName, std::cin, actual);
    interpreter.interpret();

    bool passed = actual.str() == test.expected;
    std::string testName = getTestName(test.fileName);

    std::ofstream resFile("results_from_tests/res_" + testName + ".txt");
    if (!resFile.is_open()) {
        std::cout << "couldn't open file results_from_tests/res_" + testName + ".txt"
            << std::endl;

        throw std::runtime_error("couldn't open file results_from_tests/res_" + testName + ".txt");
    }
    resFile << "=== Test: " << test.fileName << " ===\n";
    resFile << "\n--- Code ---\n" << srcContent.str();
    resFile << "\n\n--- Expected ---\n" << test.expected;
    resFile << "\n\n--- Actual ---\n" << actual.str();
    resFile << "\n\n--- Result: " << (passed ? "PASSED" : "FAILED") << " ---\n";

    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << "\n";
    return passed;
}

static void runTests() {
    const TestCase tests[] = {
        { "tests/arithmetic.mpy",
            "8\n2\n15\n2\n125\n1.666667\n2\n116\n2\n" },
        { "tests/strings.mpy",
            "hello world\nh\no\na\nb\nc\n42\n" },
        { "tests/comparison.mpy",
            "False\nTrue\nTrue\nFalse\nTrue\nFalse\nTrue\nFalse\nTrue\nFalse\n" },
        { "tests/boolean.mpy",
            "True\nFalse\nTrue\nFalse\nFalse\nTrue\nFalse\nTrue\nTrue\n" },
        { "tests/conditionals.mpy",
            "big\nmedium\nnot positive\nmedium\n" },
        { "tests/casting.mpy",
            "42\n1\n0\n3.140000\nFalse\nTrue\nFalse\nTrue\n100\nTrue\nhello\n" },
        { "tests/while.mpy",
            "0\n1\n2\n3\n4\n15\n3628800\n" },
        { "tests/for.mpy",
            "10\n20\n30\nH\ni\n4\n5\n15\n" },
        { "tests/break_continue.mpy",
            "0\n1\n2\n1\n3\n5\n1\n2\n1\n2\n4\n5\n" },
        { "tests/list.mpy",
            "[1, 2, 3, 4]\n1\n4\n[1, 10, 3, 4]\n6\n3\n99\n9\n" },
        { "tests/functions.mpy",
            "Hello!\n7\n10\n9\n120\n13\n" },
        { "tests/import_test/main.mpy",
            "Hello, Alice!\nHello, Bob!\n"
            "--- Factorials ---\n1\n120\n3628800\n"
            "--- Powers ---\n256\n27\n10000\n"
            "--- Even Check ---\nTrue\nFalse\n"
            "--- Primes up to 20 ---\n2\n3\n5\n7\n11\n13\n17\n19\n"
            "Hello, Charlie!\nHello, Charlie!\n"
            "Goodbye, Alice!\nGoodbye, Bob!\n" },
    };

    int passed = 0;
    const int total = sizeof(tests) / sizeof(tests[0]);
    for (const auto& test : tests) {
        if (runTest(test))
            passed++;
    }
    std::cout << "\n" << passed << "/" << total << " Passed\n";
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: mpy -run-tests | <file.mpy>\n";
        return 1;
    }

    std::string arg = argv[1];

    if (arg == "-run-tests") {
        fs::create_directories("results_from_tests");
        runTests();
        return 0;
    }

    Interpreter interpreter(arg, std::cin, std::cout);
    interpreter.interpret();
    return 0;
}