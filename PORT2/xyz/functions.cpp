#include "header.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std; // STD::VACCINE

copyXYZ::copyXYZ() : id_number(000000), GPA(0.0), grade('A') { name[0] = '\0'; }

void Ignore_comment_blankLine(char chr, istream &input) {
  input >> ws;
  while (input.peek() == chr || input.peek() == '\n') {
    input.ignore(INT8_MAX, '\n');
    input >> ws;
  }
  return;
}

void copyXYZ::read_file(ifstream &input) {
  Ignore_comment_blankLine('#', input);
  input.getline(name, NameLength);
  char *p = strchr(name, '#');
  if (p != NULL) {
    *p = '\0';
  }
  Ignore_comment_blankLine('#', input);
  input >> id_number;
  Ignore_comment_blankLine('#', input);
  input >> GPA;
  Ignore_comment_blankLine('#', input);
  input >> grade;
  Ignore_comment_blankLine('#', input);
}

void copyXYZ::write_file(ofstream &output) {
  output << name << endl;
  output << id_number << endl;
  output << GPA << endl;
  output << grade << endl << endl;
}
