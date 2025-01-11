#ifndef EXPR_H
#define EXPR_H

#include "../Absyn.h"

struct Expr : Absyn {
  Expr() : Absyn(0, 0);
  virtual void print() const = 0;
  virtual ~Expr() {} = default
};

#endif
