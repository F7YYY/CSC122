#include <fstream>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

bool open(const string &file, ifstream &filetxt) {
  filetxt.open(file);
  if (filetxt.fail()) {
    cout << "^FILENAME_INVALID^" << endl;
  } else {
    cout << "FOUND: " << file << "! ^_^\n" << endl;
  }
  return filetxt.is_open();
}

void isequal(const string &name, const string &ftemp, bool &found) {
  size_t i = 0;

  while (i < name.length() && tolower(name[i]) == tolower(ftemp[i])) {
    i++;
  }
  found = i >= name.length();
}

string numord(const size_t &line) {
  string suffix = "th";

  if (line % 100 / 10 != 1) {
    switch (line % 10) {
    case 1:
      suffix = "ST";
      break;
    case 2:
      suffix = "ND";
      break;
    case 3:
      suffix = "RD";
      break;
    }
  }
  return suffix;
}

bool search(const string &name, ifstream &filetxt) {
  string ftemp;
  size_t line = 0;
  bool found = false, ever_found = false;

  filetxt.peek();
  while (!filetxt.eof()) {
    line++;
    getline(filetxt, ftemp);
    isequal(name, ftemp, found);
    if (found) {
      cout << "FOUND: " << name << "! ^_^\nLINE: " << line << numord(line)
           << endl;
      ever_found = true;
    }
    filetxt.peek();
  }
  if (!ever_found) {
    cout << "^NAME_INVALID^" << endl;
  }
  return ever_found;
}

int main(void) {
  string name, file, again, list;
  ifstream filetxt;
  bool found_name;

  do {
    system("clear");
    cout << "WHO_DIS!?\n\nFILENAME: ";
    getline(cin, file);
    if (open(file, filetxt)) {
      cout << "NAME: ";
      getline(cin, name);
      found_name = search(name, filetxt);
    }
    filetxt.close();
    filetxt.clear();
    cout << "\nAGAIN?: ";
    getline(cin, again);
  } while (again[0] == 'Y' || again[0] == 'y');
  return 0;
}
