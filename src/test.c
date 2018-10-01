#include <stdio.h>
#include <stdlib.h>

#include "../include/naive.h"
#include "../include/branchless.h"
#include "../include/cmov.h"

int main() {
  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    int naive = naive_search(random_float);
    int branchless = branchless_search(random_float);
    int cmov = cmov_search(random_float);
    if (naive != branchless) {
      printf("rand_float = %f, naive = %d, branchless = %d\n", random_float, naive, branchless);
      return 1;
    }

    if (naive != cmov) {
      printf("rand_float = %f, naive = %d, cmov = %d\n", random_float, naive, cmov);
      return 1;
    }
  }

  printf("all ok\n");
  return 0;
}
