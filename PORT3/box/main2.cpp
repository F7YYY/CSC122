#include "header.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

size_t Phrase::greatestPhrasLength() {
  size_t biggest = phrases[0].length();
  for (size_t i = 0; i < 10; i++) {
    if (phrases[i].length() > biggest) {
      if (phrases[i] == "")
        break;
      biggest = phrases[i].length();
    }
  }
  return biggest;
}

void Phrase::setPhrase() { this->phrase = phrase; }

string Phrase::getPhrase() { return phrase; }

string *Phrase::getPhrases() {
  string *phra = new string[15];
  for (size_t i = 0; i < 15; ++i) {
    phra[i] = phrases[i];
  }
  return phra;
  delete[] phra;
}

void Phrase::setBorWidth(char symbol) {
  size_t length = phrase.length();
  for (size_t i = 0; i < length + 2; ++i) {
    cout << symbol;
  }
  cout << "\n";
}

void Phrase::setBorWidth(ofstream &output, char symbol) {
  size_t length = phrase.length();
  for (size_t i = 0; i < length + 2; i++) {
    output << symbol;
  }
  output << endl;
}

void Phrase::setBorWidthFile(char symbol) {
  for (size_t i = 0; i < greatestPhrasLength() + 2; ++i) {
    cout << symbol;
  }
  cout << endl;
}

void Phrase::setBorWidthFile(ofstream &output, char symbol) {
  for (size_t i = 0; i < greatestPhrasLength() + 2; ++i) {
    output << symbol;
  }
  output << endl;
}

void Phrase::setPhrases(ifstream &input) {
  for (size_t i = 0; i < 15; ++i) {
    getline(input, phrases[i]);
  }
}

void Phrase::setBorHeight(char symbol) { cout << symbol << phrase << symbol; }

void Phrase::setBorHeight(ofstream &output, char symbol) {
  output << symbol << phrase << symbol;
  output << endl;
}

void Phrase::setBorHeightFile(char symbol) {
  int length = greatestPhrasLength();
  for (size_t i = 0; i < 15; ++i) {
    cout << symbol << phrases[i] << setw(length - phrases[i].length() + 1)
         << symbol << endl;

    if (phrases[i] == "")
      break;
  }
}

void Phrase::setBorHeightFile(ofstream &output, char symbol) {
  int length = greatestPhrasLength();
  for (size_t i = 0; i < 15; ++i) {
    cout << symbol << phrases[i] << setw(length - phrases[i].length() + 1)
         << symbol << endl;

    if (phrases[i] == "")
      break;
  }
}

ostream &operator<<(ostream &output, const Phrase &p) {
  output << p.phrase;
  return output;
}

istream &operator>>(istream &input, Phrase &p) {
  cin.ignore(INT8_MAX, '\n');
  getline(input, p.phrase);
  return input;
}

void Phrase::setPremadeBorder(int choice) {
  if (choice == 1) {
    singleLine();

  } else if (choice == 2) {
    doubleLine();

  } else if (choice == 3) {
    shaded();

  } else
    singleLine();
}

void Phrase::singleLine() {
  cout << "-----------------";
  cout << "|" << phrase << "|";
  cout << "-----------------";
}

void Phrase::doubleLine() {
  cout << "=================";
  cout << "||" << phrase << "||";
  cout << "=================";
}

void Phrase::shaded() {
  cout << "=================";
  cout << "||" << phrase << "||";
  cout << "=================";
}
