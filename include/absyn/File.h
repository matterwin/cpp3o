#ifndef FILE_H
#define FILE_H 

#include <string>
#include <memory>

#include "Absyn.h"
#include "./decl/Decl.h"

// File -> (<Decl>)*
struct File : Absyn {
  std::string fileName;
  std::vector<std::shared_ptr<Decl>> decls;

  File(const std::string& name) : Absyn(0, 0), fileName(name) {}

  void print() const override {}
};

#endif
