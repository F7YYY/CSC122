#include "header.hpp"
#include <fstream>
#include <iostream>
using namespace std; // STD::VACCINE

int main() {
  Phrase p;
  ifstream input;
  ofstream output;
  string choice, phrase, frame_type, frame_ans, file, outFile, yes_no;
  char symbol;
  size_t choices;

  cout << "Do you want to choose frame type?: ";
  cin >> frame_ans;

  if (frame_ans == "Yes" || frame_ans == "Y" || frame_ans == "y") {
    cout << "Choices of frame types: "
            "Single line(S)"
            "Double line(D) or "
            "Shaded(SD)\n\n"
            "Please choose one:  ";
    cin >> frame_type;
    cout << "\n\nPlease input the phrase: ";
    cin.ignore(INT8_MAX, '\n');
    cin >> phrase;

    if (frame_type == "S") {
      p.setPremadeBorder(1);
    } else if (frame_type == "D") {
      p.setPremadeBorder(2);
    } else if (frame_type == "SD") {
      p.setPremadeBorder(3);
    } else {
      cout << "Error\n\n";
    }
  }

  cout << "\n\nEnter any symbol for the use of border: ";
  cin >> symbol;
  cout << "\n\nDo you want to get the phrase from a file: ";
  cin >> choice;

  if (choice == "yes" || choice == "y") {
    cout << "Enter the name of the file:   ";
    cin >> file;
    input.open(file.c_str(), ios::in);
    p.setPhrases(input);
    choices = 1;
  } else {
    cout << "Please enter the phrase: ";
    cin >> p;
  }

  cout << "Do you want to print the result out in the file?: ";
  cin >> yes_no;

  if (yes_no == "yes" || yes_no == "y") {
    cout << "Please enter the name of the file: ";
    cin >> outFile;
    output.open(outFile.c_str(), ios::out);
    if (choices != 1) {
      p.setBorWidth(output, symbol);
      p.setBorHeight(output, symbol);
      cout << "\n";
      p.setBorWidth(output, symbol);
    } else {
      p.setBorWidthFile(output, symbol);
      p.setBorHeightFile(output, symbol);
      p.setBorWidthFile(output, symbol);
    }
    cout << endl;
  } else {
    if (choices != 1) {
      p.setBorWidth(symbol);
      p.setBorHeight(symbol);
      cout << "\n";
      p.setBorWidth(symbol);
    } else {
      p.setBorWidthFile(symbol);
      p.setBorHeightFile(symbol);
      p.setBorWidthFile(symbol);
    }
  }
  output.close();
  output.clear();
  input.close();
  input.clear();
}
