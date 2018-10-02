#pragma once
#include "data.h"

int naive_alt_search(float target) {
  int half = 0, mid = 0, n = NUM_FLOATS, high = n - 1;

  while ((half = n / 2) > 0) {
    mid = high - half;
    if (arr[mid] >= target) high = mid;
    n -= half;
  }

  return high;
}
