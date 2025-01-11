#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>

// #include "Absyn.h"
#include "File.h"

// Program -> (<File>)*
struct Program : Absyn {
  std::string exe;
  std::vector<std::shared_ptr<File>> files;

  Program(const std::string& exeName) : Absyn(0, 0), exe(exeName) {}

  void print() const override {
    for (auto& f : files) {
      std::cout << "File: " << f->fileName << std::endl;
      f->print();
    }
  }
};

#endif
