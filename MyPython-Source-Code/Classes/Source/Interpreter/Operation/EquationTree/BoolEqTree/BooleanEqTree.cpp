#include "../../../../../Header/Interpreter/Operation/EquationTree/BooleanEqTree/BooleanEqTree.h"

#include "../../../../../Header/Interpreter/MpySymbols.h"
using std::unique_ptr;

BooleanEqTree::BooleanEqTree(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : EquationTree(std::move(left), std::move(right)) { }
