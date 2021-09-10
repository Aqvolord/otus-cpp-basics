#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
public:
    Div(ASTNode* num1, ASTNode* num2)
        : ASTNode(std::string(), { num1 }, { num2 })
        , _num1(num1), _num2(num2) {}

    ASTNode* number1() const { return _num1; }
    ASTNode* number2() const { return _num2; }

private:
    ASTNode* _num1;
    ASTNode* _num2;
};
