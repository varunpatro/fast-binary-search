#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/data.h"

void reorder(size_t const start, size_t const end, size_t const level, size_t const clevel) {
  if (start >= end){
    return;
  }

  size_t const mid = start + ((end - start) / 2);

  if (clevel == level) {
    printf("%f,\n", arr[mid]);
    return;
  }

  reorder(start,   mid, level, clevel + 1);
  reorder(mid + 1, end, level, clevel + 1);
}

void level_by_level(int size, int max_levels) {
  for(size_t level = 0; level < max_levels; level++) {
    reorder(0, size, level, 0);
  }
}

int main(int argc, char** argv) {
  printf("0, // first element is not used\n");
  level_by_level(NUM_FLOATS, log2(NUM_FLOATS) + 1);
  return 0;
}
