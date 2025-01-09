#ifndef VAR_H
#define Var_H 

#include <string>

#include "Absyn.h"
#include "Identifier.h"

// Var -> <Identifier>
struct Var : Absyn {
  Identifier id;

  Var(const Identifier id, int l, int c) 
    : Absyn(l, c), id(id) {} 

  void print() const override {
    std::cout << id.value << std::endl;
  }
};

#endif
