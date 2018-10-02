#include <stdio.h>
#include <stdlib.h>

#include "../include/naive.h"
#include "../include/naive_alt.h"
#include "../include/branchless.h"
#include "../include/cmov.h"

int main() {
  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    int naive = naive_search(random_float);
    int naive_alt = naive_alt_search(random_float);
    int branchless = branchless_search(random_float);
    int cmov = cmov_search(random_float);

    if (naive != naive_alt) {
      printf("i = %d, rand_float = %f, naive = %f, naive_alt = %f\n", i, random_float, arr[naive], arr[naive_alt]);
      return 1;
    }

    if (naive != cmov) {
      printf("i = %d, rand_float = %f, naive = %d, cmov = %d\n", i, random_float, naive, cmov);
      return 1;
    }

    if (naive != branchless) {
      printf("i = %d, rand_float = %f, naive = %f, branchless = %f\n", i, random_float, arr[naive], arr[branchless]);
      return 1;
    }

  }

  printf("all ok\n");
  return 0;
}
