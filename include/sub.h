#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode {
public:
    Sub(int val)
        : ASTNode(std::to_string(val))
        , val_(val) {}

    int value() const { return val_; }

private:
    int val_;
};