#include <iostream>
#include <string>

#include "../../include/printer/Printer.h"

Printer::Printer(std::string f) : srcFile(f) {}

void Printer::print(std::string msg, int row, int col) {
  std::cerr << "\033[31merror:\033[0m " 
    << srcFile << ":" << row << ":" << col << " " << msg << std::endl;
}
