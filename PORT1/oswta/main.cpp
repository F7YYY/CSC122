#include "header.hpp"
#include <iostream>
#include <vector>
using namespace std; // STD::VACCINE

int main() {
  vector<long> ListMenuChoicesLong;
  ListMenuChoicesLong.push_back(2);
  ListMenuChoicesLong.push_back(6);
  ListMenuChoicesLong.push_back(5);
  ListMenuChoicesLong.push_back(84);
  ListMenuChoicesLong.push_back(77);
  ListMenuChoicesLong.push_back(4);
  ListMenuChoicesLong.push_back(83);
  cout << Bounded_Both_Ends(15.5, 233.3,
                            "Enter a number between 15.5 - 233.3: ");
  cout << Bounded_Both_Ends(110L, 2288L, "Enter a number between 110 - 2288: ");
  cout << char_In_Middle('a', 'h',
                         "Enter a character which is in inbetween A - H: ");
  cout << List_Menu_Choices_Long(ListMenuChoicesLong,
                                 "Please choose from these: ");
  vector<double> ListMenuChoicesDouble;
  ListMenuChoicesDouble.push_back(2.5);
  ListMenuChoicesDouble.push_back(6.8);
  ListMenuChoicesDouble.push_back(5.5);
  ListMenuChoicesDouble.push_back(84.9);
  ListMenuChoicesDouble.push_back(77.6);
  ListMenuChoicesDouble.push_back(4.1);
  ListMenuChoicesDouble.push_back(83.4);
  cout << Bounded_Lower_Range(35.8,
                              "Input a number which is bigger than 35.8: ");
  cout << Bounded_Lower_Range(66L,
                              "Input a number which is bigger than 66!!!: ");
  cout << char_Lower_Bound('h', "Enter a character which is bigger than h: ");
  cout << List_Menu_Choices_Double(ListMenuChoicesDouble,
                                   "Please choose from one of them: ");
  vector<char> ListMenuChoicesChar;
  ListMenuChoicesChar.push_back('c');
  ListMenuChoicesChar.push_back('q');
  ListMenuChoicesChar.push_back('y');
  ListMenuChoicesChar.push_back('o');
  ListMenuChoicesChar.push_back('e');
  ListMenuChoicesChar.push_back('v');
  ListMenuChoicesChar.push_back('a');
  cout << Bounded_Upper_Range(44.66,
                              "Input a number which is smaller than 44.66: ");
  cout << Bounded_Upper_Range(3000L,
                              "Input a number which is smaller than 3000: ");
  cout << char_Upper_Bound('h',
                           "Enter a character which is in smaller than H: ");
  cout << List_Menu_Choices_Char(ListMenuChoicesChar,
                                 "Please choose from one of the character: ");
}
