#pragma once

#include <string>

#include "astnode.hpp"

class Variable : public ASTNode {
public:
    Variable(std::string val)
        : ASTNode(std::string(val))
        , _val(val) {}

    std::string value() const { return _val; }

private:
    std::string _val;
};