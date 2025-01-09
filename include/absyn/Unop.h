#ifndef BINOP_H
#define BINOP_H

#include <string>
#include <iostream>
#include "Absyn.h"

// UnOp -> [++, --, -, !, &]
struct Unop : Absyn {
  std::string unop;

  Unnop(const std::string& value, int l, int c) 
    : Absyn(l, c), unop(value) {}

  void print() const override {

  }
};

#endif
