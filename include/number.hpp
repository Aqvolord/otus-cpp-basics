#pragma once

#include <string>

#include "astnode.hpp"

class Number : public ASTNode {
  public:
    Number(int val)
        : ASTNode(std::to_string(val))
        , _val(val) {}

    int value() const { return _val; }

  private:
    int _val;
};
