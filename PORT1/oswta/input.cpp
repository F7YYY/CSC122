#include <cmath>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std; // STD::VACCINE

double Bounded_Both_Ends(double lowerBound, double upperBound, string prompt) {
  double number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number <= lowerBound || number >= upperBound);
  return number;
}

long Bounded_Both_Ends(long lowerBound, long upperBound, string prompt) {
  long number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number <= lowerBound || number >= upperBound);
  return number;
}

char char_In_Middle(char lowerChar, char upperChar, string prompt) {
  char entry;
  do {
    cout << endl << prompt;
    cin >> entry;
    toupper(entry);
  } while (entry < lowerChar && entry > upperChar);
  return entry;
}

long List_Menu_Choices_Long(vector<long> &choices, string prompt) {
  long input;
  bool stopLoop = false;
  for (auto i : choices) {
    cout << i << endl;
  }
  do {
    cout << prompt;
    cin >> input;
    cin.clear();
    for (vector<long>::size_type i = 0; i < choices.size() && !stopLoop; i++) {
      if (abs(choices[i] - input) <= 1e-6) {
        stopLoop = true;
      }
    }
  } while (cin.fail() || !stopLoop);
  return input;
}

double Bounded_Lower_Range(double lowerBound, string prompt) {
  double number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number < lowerBound);
  return number;
}

long Bounded_Lower_Range(long lowerBound, string prompt) {
  long number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number < lowerBound);
  return number;
}

char char_Lower_Bound(char lower_Bound_Char, string prompt) {
  char entry;
  do {
    cout << endl << prompt;
    cin >> entry;
    tolower(entry);
  } while (entry < lower_Bound_Char);
  return entry;
}

double List_Menu_Choices_Double(vector<double> &choices, string prompt) {
  double input;
  bool stopLoop = false;
  for (auto i : choices) {
    cout << i << endl;
  }
  do {
    cout << prompt;
    cin >> input;
    cin.clear();
    for (vector<double>::size_type i = 0; i < choices.size() && !stopLoop;
         i++) {
      if (abs(choices[i] - input) <= 1e-6) {
        stopLoop = true;
      }
    }
  } while (cin.fail() || !stopLoop);
  return input;
}

double Bounded_Upper_Range(double upperBound, string prompt) {
  double number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number > upperBound);
  return number;
}

long Bounded_Upper_Range(long upperBound, string prompt) {
  long number;
  do {
    cout << endl << prompt;
    cin >> number;
  } while (number > upperBound);
  return number;
}

char char_Upper_Bound(char Upper_Bound_Char, string prompt) {
  char entry;
  do {
    cout << endl << prompt;
    cin >> entry;
    toupper(entry);
  } while (entry < Upper_Bound_Char);
  return entry;
}

double List_Menu_Choices_Char(vector<char> &choices, string prompt) {
  char input;
  bool stopLoop = false;
  for (auto i : choices) {
    cout << i << endl;
  }
  do {
    cout << prompt;
    cin >> input;
    cin.clear();
    for (vector<double>::size_type i = 0; i < choices.size() && !stopLoop;
         i++) {
      if (abs(choices[i] - input) <= 1e-6) {
        stopLoop = true;
      }
    }
  } while (cin.fail() || !stopLoop);
  return input;
}
