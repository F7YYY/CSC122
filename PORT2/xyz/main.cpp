#include "header.hpp"
#include <fstream>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

int main() {
  ifstream input_file;
  ofstream output_file;
  copyXYZ transfer_data;
  string filename;

  cout << "\n\nPlease enter the name of your data/input file: ";
  cin >> filename;
  input_file.open(filename.c_str());
  while (input_file.fail()) {
    input_file.clear();
    cout << "\n\nSorry, I could not open '" << filename
         << "'. Please enter another name: ";
    cin >> filename;
    if (!input_file.fail()) {
      cout << "\n\nFile '" << filename << "' opened successfully!";
    }
  }
  cout << "\n\nPlease enter the name of your output file: ";
  cin >> filename;
  output_file.open(filename.c_str());
  while (output_file.fail()) {
    output_file.clear();
    cout << "\n\nSorry, I could not open '" << filename
         << "'. Please enter another name: ";
    cin >> filename;
    if (!output_file.fail()) {
      cout << "\n\nFile '" << filename << "' opened successfully!";
    }
  }
  cout << "\n\nCopying data.....";
  input_file.peek();
  while (!input_file.eof()) {
    transfer_data.read_file(input_file);
    transfer_data.write_file(output_file);
    input_file.peek();
  }
  cout << "\nDone copying data!\n";
  return 0;
}
