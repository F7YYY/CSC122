#include "set.hpp"
#include "input.hpp"
#include "ssort.hpp"
#include <cctype>
#include <iostream>
using namespace std; // STD::VACCINE

long Set::find(const long item) const {
  return bin_search(the_set, 0, cur_elem - 1, item);
}

void Set::arrange(void) { sort(the_set, 0, cur_elem - 1); }

bool Set::add_elem(const long item) {
  bool worked = false;

  if (cur_elem < MAX_SET) {
    worked = true;
    the_set[cur_elem++] = item;
    if (cur_elem > 1) {
      arrange();
      rem_dupl();
    }
  } else if (cur_elem == MAX_SET) {
    worked = true;
    if (MAX_SET == 0) {
      MAX_SET = 2;
    } else
      MAX_SET *= 2;
    long *t = new (nothrow) long[MAX_SET];
    if (t != nullptr) {
      for (long i = 0; i != cur_elem; i++)
        t[i] = the_set[i];
    }
    delete[] the_set;
    the_set = t;
    the_set[cur_elem++] = item;
  }
  return worked;
}

Set::Set(const Set &set)
    : MAX_SET(set.MAX_SET), the_set(new (nothrow) long[set.MAX_SET]),
      cur_elem(set.cur_elem) {
  if (the_set != nullptr) {
    for (long i = 0; i != cur_elem; i++) {
      the_set[i] = set.the_set[i];
    }
  } else {
    cur_elem = MAX_SET = 0;
  }
}

Set &Set::operator=(const Set &set) {
  if (&set != this) {
    delete[] the_set;
    the_set = new (nothrow) long[set.MAX_SET];
    if (the_set != nullptr) {
      MAX_SET = set.MAX_SET;
      cur_elem = set.cur_elem;
      for (long i = 0; i != cur_elem; ++i) {
        the_set[i] = set.the_set[i];
      }
    } else {
      cur_elem = 0;
      MAX_SET = 0;
    }
  }
  return *this;
}

void Set::rem_elem(const long item, const long from_where) {
  for (long i = from_where; i < (cur_elem - 1); i++) {
    the_set[i] = the_set[i + 1];
  }
  cur_elem--;
}

Set::Set(void) : MAX_SET(0), the_set(nullptr), cur_elem(0) {}

bool Set::ismember(const long item) const { return (find(item) >= 0); }

bool Set::union_with(const Set &set) {
  for (long i = 0; i < set.cur_elem; i++) {
    add_elem(set.the_set[i]);
  }
  return true;
}

bool Set::difference(const Set &set) {
  for (long i = 0; i < set.cur_elem; i++) {
    rem_elem(set.the_set[i]);
  }
  return true;
}

// this is TERRIBLY inefficient!!!  MUST fix someday...
bool Set::intersection(const Set &set) {
  Set t(*this);      // my twin?
  t.difference(set); // remove common parts
  difference(t);     // now remove rest from me
  return true;
}

bool Set::rem_elem(const long item) {
  long at;

  if ((at = find(item)) >= 0) {
    rem_elem(item, at);
  }
  return (at >= 0);
}

void Set::output(ostream &out) const {
  long i;

  out << " { ";
  for (i = 0; i < cur_elem; i++) {
    out << the_set[i] << "  ";
    if (((i + 1) % 7) == 0) {
      out << endl << "   ";
    }
  }
  out << "}";
  if ((i % 7) == 0) {
    out << endl;
  }
}

void Set::input(istream &in) {
  char brace;
  long num;

  in >> brace;
  while (!in.eof() && isdigit(peek(in))) {
    in >> num;
    add_elem(num);
  }
  in >> brace;
}

void Set::rem_dupl(void) {
  long i = 0;

  while (i < (cur_elem - 1)) {
    if (the_set[i] == the_set[i + 1]) {
      rem_elem(the_set[i], i);
    } else {
      i++;
    }
  }
}

bool Set::full(void) const { return (cur_elem == MAX_SET); }
