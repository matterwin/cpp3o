#ifndef STMT_H
#define STMT_H 

#include "../Absyn.h"

struct Stmt : Absyn {
  Stmt(int l, int c) : Absyn(l, c) {}
  virtual void print() const = 0;
};

#endif
