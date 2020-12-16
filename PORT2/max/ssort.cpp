#include "ssort.hpp"

// Searching function...
long bin_search(const long arr[], const long bot, const long top,
                const long item) {
  long mid, low = bot, high = top;

  if (low <= high) {
    mid = (high + low) / 2;
    while ((low <= high) && (arr[mid] != item)) {
      if (arr[mid] < item) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      mid = (high + low) / 2;
    }
  }
  return ((low > high) ? (bot - 1) : (mid));
}

// Sort an array of elements from the low index to the high index.
void sort(long array[], const long low, const long high) {
  long done_thru = high, position;
  bool did_swap = true;

  while ((done_thru >= low) && (did_swap)) {
    did_swap = false;
    for (position = low; position < done_thru; position++) {
      if (array[position] > array[position + 1]) {
        swap(array[position], array[position + 1]);
        did_swap = true;
      }
    }
    done_thru--;
  }
  return;
}
