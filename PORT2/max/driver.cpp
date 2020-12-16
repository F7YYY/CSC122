#include "input.hpp"
#include "set.hpp"
#include <cctype>
#include <iostream>
using namespace std; // STD::VACCINE

int main(void) {
  Set x, y, z;
  bool quit;
  long newone;

  do {
    cout << "Enter a long #:  ";
    cin >> newone;
    if (!x.ismember(newone)) {
      x.add_elem(newone);
      cout << "Value added to list!" << endl;
    } else {
      cout << "You've already entered that!" << endl;
    }
    quit =
        toupper(get_in_set("YyNn", "Would you like to enter more?  ")) == 'N';
  } while (!quit);

  cout << "Overall, you entered:  " << endl;
  x.output(cout);
  cout << endl;

  cout << "Please enter a set of long integers:  ";
  x.input(cin);
  cout << endl << "You entered:\n";
  x.output(cout);
  cout << endl;

  cout << "Please enter another set of long integers:  ";
  y.input(cin);
  cout << endl << "You entered:\n";
  y.output(cout);
  cout << endl;

  cout << "The union of the two sets is:\n";
  z = x;
  z.union_with(y);
  z.output(cout);
  cout << endl;

  cout << "The intersection of the two sets is:\n";
  z = x;
  z.intersection(y);
  z.output(cout);
  cout << endl;
  return 0;
}
