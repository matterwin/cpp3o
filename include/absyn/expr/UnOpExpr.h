#ifndef UN_OP_EXPR_H
#define UN_OP_EXPR_H

#include "Expr.h"
#include "../Unop.h"

// Expr -> <UnOp> <Expr>
//      | <Expr> <UnOp>
struct UnOpExpr : Expr {
  Expr expr;
  Unop unop;

  UnOpExpr(Expr l, Expr r, int l, int c, Unop op)
    : Absyn(l, c), lhs(l), rhs(r), unop(op) {}

  void print() const override {}
}

#endif
