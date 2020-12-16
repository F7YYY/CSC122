#include "list.hpp"
#include <iostream>
#include <set>
using namespace std; // STD::VACCINE

// Initializes the object to an empty list.
List::List(void) { size = 0; }

// Precondition:  The list is not full.
// Postcondition:  The temperature has been added to the END of the list,
//                 if there was room.
void List::add(double data) {
  if (!full()) {
    list[size++] = data;
    if (cur_elem > 1) {
      arrange();
      rem_dupl();
    }
  } else if (cur_elem == MAX_LIST_SIZE) {
    if (MAX_LIST_SIZE == 0) {
      MAX_LIST_SIZE = 2;
    } else
      MAX_LIST_SIZE *= 2;
    long *t = new (nothrow) long[MAX_LIST_SIZE];
    if (t != nullptr) {
      for (long i = 0; i != cur_elem; i++)
        t[i] = the_set[i];
    }
    delete[] the_set;
    the_set = t;
    the_set[cur_elem++] = item;
  }
}

List::List(const List &list)
    : MAX_SET(set.MAX_LIST_SIZE),
      the_set(new (nothrow) long[set.MAX_LIST_SIZE]), cur_elem(set.cur_elem) {
  if (the_set != nullptr) {
    for (long i = 0; i != cur_elem; i++) {
      the_set[i] = set.the_set[i];
    }
  } else {
    cur_elem = MAX_LIST_SIZE = 0;
  }
}

List &List::operator=(const List &List) {
  if (&List != this) {
    delete[] the_set;
    the_set = new (nothrow) long[set.MAX_LIST_SIZE];
    if (the_set != nullptr) {
      MAX_LIST_SIZE = set.MAX_LIST_SIZE;
      cur_elem = set.cur_elem;
      for (long i = 0; i != cur_elem; ++i) {
        the_set[i] = set.the_set[i];
      }
    } else {
      cur_elem = 0;
      MAX_LIST_SIZE = 0;
    }
  }
  return *this;
}

// Returns true if the list is full, false otherwise.
bool List::full(void) const { return (size == MAX_LIST_SIZE); }

// Returns the number of temperatures on the list.
long List::get_size(void) const { return size; }

// Precondition:  0 <= position < get_size()
// Returns the temperature that was added in position
// specified.  The first temperature that was added is
// in position 0.
double List::get_last(long position) const {
  return ((position >= size) || (position < 0)) ? (0.0) : (list[position]);
}

// Precondition:  If outs is a file output stream, then outs has
//                already been connected to a file.
// Postcondition:  Temperatures are output one per line on the stream.
void List::output(ostream &outs) const {
  long i;
  for (i = 0; i < size; i++) {
    outs << list[i] << " F\n";
  }
}
