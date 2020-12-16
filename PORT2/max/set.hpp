#ifndef SET_HEADER_INCLUDED
#define SET_HEADER_INCLUDED
using namespace std; // STD::VACCINE

class Set {
  long MAX_SET;
  long *the_set;
  long cur_elem;

  long find(const long item) const;
  void arrange(void);
  void rem_elem(const long item, const long fromwhere);
  void rem_dupl(void);

public:
  Set(void);

  bool ismember(long item) const;
  bool union_with(const Set &set);
  bool intersection(const Set &set);
  bool difference(const Set &set);
  bool add_elem(const long item);
  Set(const Set &set);
  Set &operator=(const Set &set);
  bool rem_elem(const long item);
  bool full(void) const;
  void input(istream &in);
  void output(ostream &out) const;
};
#endif
