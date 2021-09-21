#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
public:
    Div(ASTNode* num1, ASTNode* num2)
        : ASTNode(std::string("/"), num1, num2) {}
};
