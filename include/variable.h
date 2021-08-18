#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(int val)
        : ASTNode(std::to_string(val))
        , val_(val) {}

    int value() const { return val_; }

private:
    int val_;
};