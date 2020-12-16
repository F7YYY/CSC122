#ifndef COPY_XYZ_HEADER_H
#define COPY_XYZ_HEADER_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

class copyXYZ {
public:
  copyXYZ();
  void read_file(ifstream &input);
  void write_file(ofstream &output);

private:
  static const int NameLength = 30;
  int id_number;
  double GPA;
  char grade, name[NameLength];
};
#endif
