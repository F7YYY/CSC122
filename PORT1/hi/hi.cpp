#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

void msgt_skipper(const string &s, bool skips, bool skipp, size_t &i,
                  size_t &skipped) { // OPTIONAL - CALLER SKIPWS && SKIP!?
  while ((skips && s[i] == ' ') || (skipp && ispunct(s[i]))) {
    skipped++;
    i++;
  }
}

short strcomp(const string &s1, const string &s2, bool skips,
              bool skipp) { // PROCESSES USER'S RESPONCE
  short comp = 0;
  size_t skipped_1 = 0, skipped_2 = 0, i = 0, j = 0;

  for (i, j; i < s1.length() && j < s2.length() && comp == 0; i++, j++) {
    msgt_skipper(s1, skips, skipp, i, skipped_1);
    msgt_skipper(s2, skips, skipp, j, skipped_2);
    if (!isdigit(s1[i]) || !isdigit(s2[j])) {
      if (toupper(s1[i]) != toupper(s2[j])) {
        comp = toupper(s1[i]) < toupper(s2[j]) ? -1 : 1;
      }
    } else if (isdigit(s1[i]) && isdigit(s2[j])) { // OPTION47-OPTION47=0
      comp = static_cast<short>(stoi(s1.substr(i)) - stoi(s2.substr(j)));
    }
  }
  msgt_skipper(s1, skips, skipp, i, skipped_1);
  msgt_skipper(s2, skips, skipp, j, skipped_2);
  if (comp == 0 && s1.length() - skipped_1 != s2.length() - skipped_2) {
    if (s1.length() - skipped_1 < s2.length() - skipped_2) {
      comp = -1;
    } else
      comp = 1;
  } else
    comp = comp;
  return comp;
}

int main(void) { // REQUESTS USER'S RESPONCE
  bool skips = false, skipp = false;
  string s1, s2, ss, sp;
  short comp;

  system("clear"); // INITIAL REQUEST
  cout << "A] ENGLISH: ";
  getline(cin, s1);
  cout << "B] COMP^RE: ";
  getline(cin, s2);
  cout << "\nSKIP SPACES?: "; // OPTIONAL - SKIPWS
  getline(cin, ss);
  if (ss[0] == 'Y' || ss[0] == 'y') {
    cout << "-SKIPPING-SPACES-" << endl;
    skips = true;
  }
  cout << "SKIP PUNCTUATION?: "; // OPTIONAL - SKIP!?
  getline(cin, sp);
  if (sp[0] == 'Y' || sp[0] == 'y') {
    cout << "-SKIPPING-PUNCTUATIONS-" << endl;
    skipp = true;
  }
  comp = strcomp(s1, s2, skips, skipp);
  switch (comp) { // RETURN
  case -1:
    cout << "\n A < B\n" << comp << " < 0\n" << endl;
    break;
  case 0:
    cout << "\nA == B\n" << comp << " == 0\n" << endl;
    break;
  case 1:
    cout << "\nA > B\n" << comp << " > 0\n" << endl;
    break;
  default:
    cout << "\n#: " << comp << endl;
    break;
  }
  return 0;
}
