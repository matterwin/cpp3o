#ifndef BREAK_STMT_H
#define BREAK_STMT_H

#include <iostream>

#include "Stmt.h"

struct BreakStmt : Stmt {
  BreakStmt(int l, int c) : Stmt(l, c) {}
  void print() const override {
    std::cout << "break" << std::endl;
  }
};

#endif
