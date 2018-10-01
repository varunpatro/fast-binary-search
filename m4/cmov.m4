#pragma once
#include "data.h"

int cmov_search(float target) {
  int half = 0, mid = 0;
  int low = 0, n = NUM_FLOATS; // NUM_FLOATS is the size of the array

  while ((half = n / 2) > 0) {
    mid = low + half;
    int val = arr[mid];
    low = (val < target) ? mid : low;
    n -= half;
  }

  return low;
}
