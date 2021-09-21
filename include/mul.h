#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
public:
    Mul(ASTNode* num1, ASTNode* num2)
        : ASTNode(std::string("*"), num1, num2) {}
};
