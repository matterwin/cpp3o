#include <iostream>
#include <string>

#include "../include/lexer/lexer.h"

int main(int argc, char** argv) {
  std::cout << argc << std::endl;

  std::string arg1 = argv[0];

  for (int i = 0; i < argc; i++) 
    std::cout << argv[i] << " ";

  std::cout << std::endl;
  return 0;
}
