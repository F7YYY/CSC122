#include <iomanip>
#include <iostream>
using namespace std; // STD::VACCINE

void Additional_table() {
  short size;
  int down, across;

  cout << "What size should the additional table be?    \n";
  do {
    cin >> size;
    if (size >= 11)
      cout << size << " is too large of a table to print.\n\n";
    if (size <= 10) {
      cout << "Thank you...Calculating...\n\n";
    }
  } while (size >= 11);
  cout << "  + |";
  for (down = 1; down <= size; ++down)
    cout << setw(4) << down;
  cout << "\n";
  for (across = 1; across <= size; ++across) {
    cout << "-----";
  }
  for (down = 1; down <= size; ++down)
    for (down = 1; down <= size; ++down) {
      cout << "\n " << setw(2) << down << " |";
      for (across = 1; across <= size; ++across)
        cout << setw(4) << down + across;
    }
}

void Multiplication_table() {
  short size;
  int i, down, across;

  cout << "What size should the multiplication table be?: ";
  do {
    cin >> size;
    if (size >= 11)
      cout << size << " is too large of a table to print.\n\n";
    if (size <= 10) {
      cout << "Thank you...Calculating...\n\n";
    }
  } while (size >= 11);
  cout << "  * |";
  for (down = 1; down <= size; ++down)
    cout << setw(4) << down;
  cout << "\n";
  for (across = 1; across <= size; ++across) {
    cout << "-----";
  }
  for (down = 1; down <= size; ++down)
    for (down = 1; down <= size; ++down) {
      cout << "\n " << setw(2) << down << " |";
      for (across = 1; across <= size; ++across)
        cout << setw(4) << down * across;
    }
}

void Subtraction_table() {
  short size;
  int i, down, across;

  cout << "What size should the subtraction table be?: ";
  do {
    cin >> size;
    if (size >= 11)
      cout << size << " is too large of a table to print.\n\n";
    if (size <= 10) {
      cout << "Thank you...Calculating...\n\n";
    }
  } while (size >= 11);
  cout << "  - |";
  for (down = 1; down <= size; ++down)
    cout << setw(4) << down;
  cout << "\n";
  for (across = 1; across <= size; ++across) {
    cout << "-----";
  }
  for (down = 1; down <= size; ++down)
    for (down = 1; down <= size; ++down) {
      cout << "\n " << setw(2) << down << " |";
      for (across = 1; across <= size; ++across)
        cout << setw(4) << down - across;
    }
}

void Division_table() {
  double size;
  double i, down, across;

  cout << "What size should the division table be?: ";
  do {
    cin >> size;
    if (size >= 11)
      cout << size << " is too large of a table to print.\n\n";

    if (size <= 10) {
      cout << "Thank you...Calculating...\n\n";
    }
  } while (size >= 11);
  cout << "  / |";
  for (down = 1; down <= size; ++down)
    cout << setw(5) << down;
  cout << "\n";
  for (across = 1; across <= size; ++across) {
    cout << "------";
  }
  for (down = 1; down <= size; ++down)
    for (down = 1; down <= size; ++down) {
      cout << "\n " << setw(2) << down << " |";
      for (across = 1; across <= size; ++across)
        cout << setw(5) << setprecision(2) << (down / across);
    }
}

void Remainder_table() {
  short size;
  int i, down, across;

  cout << "What size should the remainder table be?: ";
  do {
    cin >> size;
    if (size >= 11)
      cout << size << " is too large of a table to print.\n\n";
    if (size <= 10) {
      cout << "Thank you...Calculating...\n\n";
    }
  } while (size >= 11);
  cout << "  % |";
  for (down = 1; down <= size; ++down)
    cout << setw(4) << down;
  cout << "\n";
  for (across = 1; across <= size; ++across) {
    cout << "-----";
  }
  for (down = 1; down <= size; ++down)
    for (down = 1; down <= size; ++down) {
      cout << "\n " << setw(2) << down << " |";
      for (across = 1; across <= size; ++across)
        cout << setw(4) << (down % across);
    }
}

int main() {
  char choice;

  cout << "\n\t\t\tWelcome to the Math Table Program!!!";
  do {
    cout << "\n\nTable Menu\n\n"
            "1) Addition table\n"
            "2) Multiplication table\n"
            "3) Subtraction table\n"
            "4) Division table\n"
            "5) Remainder table\n"
            "6) Quit\n\n"
            "Choice:  ";
    cin >> choice;
    if (choice == '1' || choice == 'A' || choice == 'a') {
      Additional_table();
    } else if (choice == '2' || choice == 'M' || choice == 'm') {
      Multiplication_table();
    } else if (choice == '3' || choice == 'S' || choice == 's') {
      Subtraction_table();
    } else if (choice == '4' || choice == 'D' || choice == 'd') {
      Division_table();
    } else if (choice == '5' || choice == 'R' || choice == 'r') {
      Remainder_table();
    } else {
      if (choice == '6' || choice == 'Q' || choice == 'q') {
        cout << "\n\nThank you for using the MVP!!\n";
        return 0;
      }
    }
  } while (choice != 'q');
}
