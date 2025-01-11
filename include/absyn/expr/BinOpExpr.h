#ifndef BIN_OP_EXPR_H
#define BIN_OP_EXPR_H

#include "Expr.h"
#include "../Binop.h"

// Expr -> <Expr> <BinOp> <Expr>
struct BinOpExpr : Expr {
  Expr lhs, rhs;
  Binop binop;

  BinOpExpr(Expr l, Expr r, int l, int c, Binop op)
    : Absyn(l, c), lhs(l), rhs(r), binop(op) {}

  void print() const override {}
}

#endif
