// OTUS C++ basic course homework.
// ASTNode

#pragma once

#include <cctype>
#include <iostream>
#include <string>

class ASTNode {
  public:
    //  онструктор листа (узел без дочерних узлов)
    explicit ASTNode(const std::string &repr);

    //  онструктор узла (с одним или двум€ дочерними узлами)
    ASTNode(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    ASTNode(const ASTNode &other) = delete;

    ASTNode &operator=(const ASTNode &other) = delete;

    ~ASTNode();

    // ѕредставлени€ имени узла в виде строки
    std::string repr() const { return repr_; }

    // ѕечать всего дерева в текстовом виде
    void print(std::ostream &out) const;

  private:
    void inner_print(std::ostream &out, size_t indent) const;

    std::string repr_;
    ASTNode *lhs_;
    ASTNode *rhs_;
};


