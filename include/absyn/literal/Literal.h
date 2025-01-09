#ifndef LITERAL_H
#define LITERAL_H

#include "../Absyn.h"

#include <string>
#include <iostream>

// Base Literal class
struct Literal : Absyn {
  Literal(int l, int c) : Absyn(l, c) {}
  virtual void print() const = 0;
};

#endif

