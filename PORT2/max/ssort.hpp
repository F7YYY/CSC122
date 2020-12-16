#ifndef SEARCH_AND_SORT_LIBRARY_HEADER_INCLUDED
#define SEARCH_AND_SORT_LIBRARY_HEADER_INCLUDED

// Swapping function...
inline void swap(long &x, long &y) {
  long t = x;
  x = y;
  y = t;
  return;
}

// Searching function...
long bin_search(const long arr[], const long bot, const long top,
                const long item);

// Sort an array of elements from the low index to the high index.
void sort(long array[], const long low, const long high);
#endif
