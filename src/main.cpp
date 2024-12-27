#include <iostream>
#include <string>
#include <memory>

#include "../include/lexer/lexer.h"

int main(int argc, char** argv) {
  std::cout << argc << std::endl;

  std::string arg1 = argv[0];

  for (int i = 0; i < argc; i++) 
    std::cout << argv[i] << " ";

  std::cout << std::endl;

  std::unique_ptr<Lexer> lexer = std::make_unique<Lexer>();

  lexer->test();

  return 0;
}
