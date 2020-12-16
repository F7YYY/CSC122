#include <cstring>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

class scaling {
public:
  char *searching(const char *read, unsigned int start, unsigned int end);
};

char *scaling::searching(const char *read, unsigned int start,
                         unsigned int end) {
  if (start > strlen(read) && end > strlen(read)) {
    cout << "Not valid" << endl;
    exit(1);
  }
  char *returntheValue;
  returntheValue = strndup(read + start, end);
  return returntheValue;
}

int main() {
  scaling thing;
  char sending[50];
  unsigned int position, end_position;
  string printing;

  cout << "Enter a sentence: ";
  cin.getline(sending, 50);
  cout << "Start: ";
  cin >> position;
  cout << "End: ";
  cin >> end_position;
  printing = thing.searching(sending, position, end_position);
  cout << "Your Original Sentence was:\t" << sending << endl;
  cout << "Your chosen phrase:\t'" << printing << "'\n";
}
