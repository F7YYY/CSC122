#ifndef A_BOX_OPEN_YE_HEADER_H
#define A_BOX_OPEN_YE_HEADER_H
#include <iostream>
using namespace std; // STD::VACCINE

class Phrase {
  string phrase;
  string phrases[15];
  size_t greatestPhrasLength();
  void singleLine();
  void doubleLine();
  void shaded();

public:
  void setPhrase();
  string getPhrase();
  string *getPhrases();
  void setBorWidth(char symbol);
  void setBorWidth(ofstream &output, char symbol);
  void setBorWidthFile(char symbol);
  void setBorWidthFile(ofstream &output, char symbol);
  void setPhrases(ifstream &input);
  void setBorHeight(char symbol);
  void setBorHeight(ofstream &output, char symbol);
  void setBorHeightFile(char symbol);
  void setBorHeightFile(ofstream &output, char symbol);
  void setPremadeBorder(int);

  friend ostream &operator<<(ostream &output, const Phrase &p);
  friend istream &operator>>(istream &input, Phrase &p);
};
#endif
