#ifndef INPUT_LIBRARY_HEADER_INCLUDED
#define INPUT_LIBRARY_HEADER_INCLUDED
#include <iostream>
using namespace std; // STD::VACCINE

// Boundaries are assumed to be solid -- low <= value <= high.
// Enum to say which end is to be bounded...
enum BoundType { Low, High, Both };

// Bounded entry function for long integers...
long get_bounded(long low, long high,
                 const char prompt[] = "Enter bounded value:  ",
                 BoundType which_end = Both);

// Overloaded for double data...
double get_bounded(double low, double high,
                   const char prompt[] = "Enter bounded value:  ",
                   BoundType which_end = Both);

// Limiting a character entry to one of a few...
char get_in_set(const char set[] = "YyNn",
                const char prompt[] = "Shall we play a game?  ",
                const char errmsg[] = "\nInvalid entry..."
                                      "try again, schmuck!\n\n");

// look at the next non-whitespace character
char peek(istream &in);
#endif
