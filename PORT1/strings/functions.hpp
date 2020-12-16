#ifndef FUNCTIONS_FUNCTIONS_H
#define FUNCTIONS_FUNCTIONS_H
#include <iostream>
#include <string>
#include <vector>
using namespace std; // STD::VACCINE

void sortVectors(vector<string> &VecBusiStr) {
  string holder;
  for (unsigned int i = 1; i < VecBusiStr.size(); i++) {
    for (unsigned int v = 0; v < VecBusiStr.size() - 1; v++) {
      if (VecBusiStr[v] > VecBusiStr[i]) {
        holder = VecBusiStr[v];
        VecBusiStr[v] = VecBusiStr[i];
        VecBusiStr[i] = holder;
      }
    }
  }
}

void displayVectors(vector<string> &VecBusiStr) {
  for (unsigned int srt = 0; srt != VecBusiStr.size(); srt++) {
    cout << VecBusiStr[srt] << "\n";
  }
}

void uno_or_many(vector<string> &OneOrMany) {
  if (OneOrMany.size() == 1) {
    cout << "\nYour businesses is: \n\n";
  } else {
    cout << "\nYour businesses are: \n\n";
  }
}
#endif
