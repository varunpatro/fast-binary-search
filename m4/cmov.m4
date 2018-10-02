#pragma once
#include "data.h"

int cmov_search(float target) {
  int half = 0, mid = 0, n = NUM_FLOATS, high = n - 1;

  while ((half = n / 2) > 0) {
    mid = high - half;
    high = (arr[mid] >= target) ? mid : high;
    n -= half;
  }

  return high;
}
