#include "input.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
using namespace std; // STD::VACCINE

// Boundaries are assumed to be solid -- low <= value <= high.
// Enum to say which end is to be bounded...
// enum BoundType { Low, High, Both };
// Bounded entry function for long integers...
long get_bounded(long low, long high,
                 const char prompt[],   // = "Enter bounded value:  "
                 BoundType which_end) { // = Both
  long value;

  cout << prompt;
  cin >> value;
  while ((((which_end == Low) || (which_end == Both)) && (low > value)) ||
         (((which_end == High) || (which_end == Both)) && (value > high))) {
    cout << "Please enter a value ";
    if (which_end == Both) {
      cout << "between " << low << " and " << high << " inclusive!";
    } else if (which_end == Low) {
      cout << "greater than or equal to " << low << "!";
    } else {
      cout << "less than or equal to " << high << "!";
    }
    cout << endl << prompt;
    cin >> value;
  }
  return value;
}

// Overloaded for double data...
double get_bounded(double low, double high,
                   const char prompt[],   // = "Enter bounded value:  "
                   BoundType which_end) { // = Both
  double value;

  cout << prompt;
  cin >> value;
  while ((((which_end == Low) || (which_end == Both)) && (low > value)) ||
         (((which_end == High) || (which_end == Both)) && (value > high))) {
    cout << "Please enter a value ";
    if (which_end == Both) {
      cout << "between " << low << " and " << high << " inclusive!";
    } else if (which_end == Low) {
      cout << "greater than or equal to " << low << "!";
    } else {
      cout << "less than or equal to " << high << "!";
    }
    cout << endl << prompt;
    cin >> value;
  }
  return value;
}

// Limiting a character entry to one of a few...
char get_in_set(
    const char set[],      // = "YyNn"
    const char prompt[],   // = "Shall we play a game?"
    const char errmsg[]) { // = "\nInvalid entry...try again, schmuck!\n\n"
  char response;

  cout << prompt;
  cin >> response;
  while (strchr(set, response) == nullptr) {
    cout << errmsg << prompt;
    cin >> response;
  }
  return response;
}

// look at the next non-whitespace character
char peek(istream &in) {
  while (isspace(in.peek())) {
    in.ignore();
  }
  return (char)in.peek();
}
