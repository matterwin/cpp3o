#ifndef RETURN_STMT_H
#define RETURN_STMT_H

#include "Stmt.h"
#include "../expr/Expr.h"

// Stmt -> return (<Expr>)? ;
struct ReturnStmt : Stmt {
  Expr expr;
  ReturnStmt(int l, int c, Expr expr)
    : Stmt(l, c), expr(expr);

  void print() const override {
    std::cout << "return";
    if (!expr) std::cout << ";" << std::endl;
    else std::cout << expr.print() << ";" << std::endl;
  }
};

#endif
