#pragma once
#include "data.h"

int search(float target) {
  int low = 0, high = NUM_FLOATS; // N is the size of the array
  while (low != high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= target) {
      /* This index, and everything below it, must not be the first element
       * greater than what we're looking for because this element is no greater
       * than the element.
       */
      low = mid + 1;
    }
    else {
      /* This element is at least as large as the element, so anything after it can't
       * be the first element that's at least as large.
       */
      high = mid;
    }
  }

  /* Now, low and high both point to the element in question. */
  return high;
}
