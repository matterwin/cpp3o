#ifndef DECL_H
#define DECL_H 

#include "../Absyn.h"

struct Decl : Absyn {
  Decl(int l, int c) : Absyn(l, c) {}
  virtual void print() const = 0;
};

#endif
