#include "header.hpp"
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

int main() {
  int NumArray[15] = {1,  2,   36,  43, 51,  63, 79, 84,
                      95, 160, 131, 12, 132, 14, 156};
  char CharArray[15] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
                        'i', 'j', 'k', 'l', 'm', 'n', '0'};
  string StrArray[15] = {"A", "C", "x", "Z", "Q", "W", "O", "K",
                         "H", "V", "m", "N", "R", "P", "S"};
  double DubArray[15] = {1.2, 2.1,  3.2,  4.4,  5.3,  6.4,  7.2, 8.8,
                         9.1, 10.0, 11.4, 12.0, 13.5, 14.4, 15.0};

  bool Num_sorting = sorting(NumArray, 0);
  bool Char_sorting = sorting(CharArray, '0');
  bool Str_sorting = sorting(StrArray, "0");
  bool Dub_sorting = sorting(DubArray, "0.0");

  if (Char_sorting == 0) {
    cout << "The array is in the correct order\n";
  } else {
    cout << "The array is not in the correct order\n";
  }
  if (Num_sorting == 0) {
    cout << "The array is in the correct order\n";
  } else {
    cout << "The array is not in the correct order\n";
  }
  if (Str_sorting == 0) {
    cout << "The array is in the correct order\n";
  } else {
    cout << "The array is not in the correct order\n";
  }
  if (Dub_sorting == 0) {
    cout << "The array is in the correct order\n";
  } else {
    cout << "The array is not in the correct order\n";
  }
  cout << endl;
  return 0;
}
