
#ifndef TYPESYSTEM_H
#define TYPESYSTEM_H

#include "../Absyn.h"
#include <iostream>
#include <memory>

/* Base Type */
struct Type : Absyn {
  Type(int l, int c) : Absyn(l, c) {}
  virtual void print() const = 0;
  virtual ~Type() = default;
};

struct VoidType : Type {
  VoidType(int l, int c) : Type(l, c) {}
  void print() const override {
    std::cout << "void";
  }
};

struct IntType : Type {
  IntType(int l, int c) : Type(l, c) {}
  void print() const override {
    std::cout << "int";
  }
};

struct BoolType : Type {
  BoolType(int l, int c) : Type(l, c) {}
  void print() const override {
    std::cout << "bool";
  }
};

struct StringType : Type {
  StringType(int l, int c) : Type(l, c) {}
  void print() const override {
    std::cout << "string";
  }
};

struct PointerType : Type {
  std::shared_ptr<Type> baseType;

  PointerType(std::shared_ptr<Type> baseType, int l, int c)
      : Type(l, c), baseType(baseType) {}

  void print() const override {
    baseType->print();
    std::cout << "*";
  }
};

struct ReferenceType : Type {
  std::shared_ptr<Type> baseType;

  ReferenceType(std::shared_ptr<Type> baseType, int l, int c)
    : Type(l, c), baseType(baseType) {}

  void print() const override {
    baseType->print();
    std::cout << "&";
  }
};

#endif

