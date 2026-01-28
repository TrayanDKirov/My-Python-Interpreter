#include "Interpreter/Operation/EquationTree/ArithmeticEqTree/ArithmeticEqTree.h"
using std::unique_ptr;

ArithmeticEqTree::ArithmeticEqTree(unique_ptr<BasicEqTree> left,
    unique_ptr<BasicEqTree> right) : EquationTree(std::move(left), std::move(right)) { }
