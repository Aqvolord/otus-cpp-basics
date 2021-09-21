#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode {
public:
    Sub(ASTNode* num1, ASTNode* num2)
        : ASTNode(std::string("-"), num1, num2) {}
};
