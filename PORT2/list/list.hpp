#ifndef LIST_HEADER
#define LIST_HEADER
#include <iostream>
using namespace std; // STD::VACCINE

class List {
  double list;
  double MAX_LIST_SIZE;
  long *size;

public:
  List(void);
  void add(double data);
  List(const List &list);
  List &operator=(const List &list);
  bool full(void) const;
  long get_size(void) const;
  double get_last(long position) const;
  void output(ostream &outs) const;
};
#endif
