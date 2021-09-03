#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
public:
    Mul(int val, )
        : ASTNode(std::to_string(val))
        , val_(val) {}

    int value() const { return val_; }

private:
    int val_;
};