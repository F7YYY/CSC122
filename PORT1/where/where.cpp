#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

int main(void) { // REQUESTS && PROCESSES USER'S RESPONSE
  string s1, s2;
  size_t pos;

  system("clear"); // INITIAL REQUEST
  cout << "ENGLISH: ";
  getline(cin, s1);
  cout << "FIND: ";
  getline(cin, s2);
  (pos = s1.find(s2)) == string::npos ? pos = -1 : pos; // PROCESSES POSITION
  cout << "\nPOSITION: " << ++pos << endl << endl;
  return 0;
}
