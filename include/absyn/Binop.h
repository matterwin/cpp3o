#ifndef BINOP_H
#define BINOP_H

#include <string>
#include <iostream>
#include "Absyn.h"

// BinOp -> [=, +, -, *, /, %, <, >, <=, >=, ==, !=, &, &&, |, ||, ^, ~]
struct Binop : Absyn {
  std::string binop;
  Binop(const std::string& value, int l, int c) : Absyn(l, c), binop(value) {}

  void print() const override {

  }
};

#endif
