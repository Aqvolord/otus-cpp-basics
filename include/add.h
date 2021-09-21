#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode {
public:
    Add(ASTNode* num1, ASTNode* num2)
        : ASTNode(std::string("+"), num1, num2) {}
};