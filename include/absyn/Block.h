#ifndef BLOCK_H
#define BLOCK_H

#include <memory>

#include "Absyn.h"
#include "./decl/Decl.h"
#include "./stmt/Stmt.h"

// Block -> { (<Stmt> | <Decl>)* }
struct Block : Absyn {
  std::vector<std::shared_ptr<Stmt>> stmts;
  std::vector<std::shared_ptr<Decl>> decls;

  Block(int l, int c) : Absyn(l, c) {}
};

#endif
