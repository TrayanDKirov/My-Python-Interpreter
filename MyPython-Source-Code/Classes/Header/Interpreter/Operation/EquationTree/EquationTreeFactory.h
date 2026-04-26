#pragma once
#include <string>
#include <vector>

#include "BasicEqTree.h"

class OperationFactory;

class EquationTreeFactory
{
    OperationFactory* operationFactory;
    std::unordered_map<int, int> endBracketIndexes;
    std::unordered_map<int, int> startBracketIndexes;
    std::unordered_map<int, int> sqEndBracketIndexes;
    std::unordered_map<int, int> sqStartBracketIndexes;
    int depth = 0;

    BasicEqTree* createPr1(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr2(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr3(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr4(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr5(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr6(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr7(const std::vector<std::string>& tokens, size_t start, size_t end);
    BasicEqTree* createPr8(const std::vector<std::string>& tokens, size_t start, size_t end);

    void findEndBracket(const std::vector<std::string>& tokens, size_t startBracketIndex, size_t end);
    void findSqEndBracket(const std::vector<std::string>& tokens, size_t startBracketIndex, size_t end);
    void initBracketIndexes(const std::vector<std::string>& tokens, size_t start, size_t end);
    void clearFactory();

public:

    EquationTreeFactory(OperationFactory* operationFactory);
    BasicEqTree* create(const std::vector<std::string>& tokens, size_t start, size_t end);
};
