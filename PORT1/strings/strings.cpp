#include "functions.hpp"
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std; // STD::VACCINE

vector<string>::size_type srt;
vector<string> businessNames;

int main() {
  string busiNames;
  char yes_or_no = 'y';

  do {
    cout << "\n\nPlease enter the name of a business: ";
    getline(cin, busiNames);
    businessNames.push_back(busiNames);
    sortVectors(businessNames);
    uno_or_many(businessNames);
    displayVectors(businessNames);
    cout << "\nAnother business?  ";
    cin >> yes_or_no;
    while (yes_or_no == 'N' || yes_or_no == 'n') {
      cout << "Thanks for using the BSP!!\n\n";
      return 0;
    }
    cin.ignore();
  } while (yes_or_no == 'Y' || yes_or_no == 'y');
}
