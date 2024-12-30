#ifndef PRINTER_H
#define PRINTER_H 

#include <string>

class Printer {
private:
  std::string srcFile;
public:
  Printer(std::string f);
  void print(std::string msg, int row, int col);
};

#endif
