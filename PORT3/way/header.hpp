#ifndef BUT_I_WANTED_TO_GO_TO_THAT_WAY_HEADER_H
#define BUT_I_WANTED_TO_GO_TO_THAT_WAY_HEADER_H
#include <cstdio>
#include <iostream>
#include <string>
using namespace std; // STD::VACCINE

template <typename int_array> bool sorting(int_array &array, int) {
  size_t size = sizeof(array) / sizeof(int);

  for (size_t i = 0; i < size - 2; i++) {
    if (array[i] > array[i + 1]) {
      return true;
    }
  }
  return false;
}

template <typename Char_array> bool sorting(Char_array &array, char) {
  size_t size = sizeof(array) / sizeof(char);

  for (size_t i = 0; i < size - 2; i++) {
    if (array[i] > array[i + 1]) {
      return true;
    }
  }
  return false;
}

template <typename Str_array> bool sorting(Str_array &array, string) {
  size_t size = sizeof(array) / sizeof(string);

  for (size_t i = 0; i < size - 2; i++) {
    if (array[i] > array[i + 1]) {
      return true;
    }
  }
  return false;
}

template <typename Dub_array> bool sorting(Dub_array &array, double) {
  size_t size = sizeof(array) / sizeof(double);

  for (size_t i = 0; i < size - 2; i++) {
    if (array[i] > array[i + 1]) {
      return true;
    }
  }
  return false;
}

template <typename Array, typename Element>

int search(const Array &arr, int bottom, int top, const Element &item) {
  int mid;

  if (bottom <= top) {
    mid = (top + bottom) / 2;
    while ((bottom <= top) && (arr[mid] != item)) {
      if (arr[mid] < item) {
        bottom = mid + 1;
      } else {
        top = mid - 1;
      }
      mid = (top + bottom) / 2;
    }
  }
  return ((bottom > top) ? (bottom - 1) : (mid));
}
#endif
