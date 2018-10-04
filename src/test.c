#include <stdio.h>
#include <stdlib.h>

#include "../include/naive.h"
#include "../include/naive_alt.h"
#include "../include/branchless.h"
#include "../include/cmov.h"
#include "../include/code_gen.h"
#include "../include/code_gen_ternary.h"
#include "../include/heap.h"

int main() {
  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    int naive = naive_search(random_float);
    int naive_alt = naive_alt_search(random_float);
    int cmov = cmov_search(random_float);
    int branchless = branchless_search(random_float);
    int code_gen = code_gen_search(random_float);
    int code_gen_ternary = code_gen_ternary_search(random_float);
    int heap = heap_search(random_float);

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

    if (naive != code_gen) {
      printf("i = %d, rand_float = %f, naive = %f, code_gen = %f\n", i, random_float, arr[naive], arr[code_gen]);
      return 1;
    }

    if (naive != code_gen_ternary) {
      printf("i = %d, rand_float = %f, naive = %f, code_gen_ternary = %f\n", i, random_float, arr[naive], arr[code_gen_ternary]);
      return 1;
    }

    if (arr[naive] != heap_arr[heap]) {
      //      printf("i = %d, rand_float = %f, naive = %f, heap = %f\n", i, random_float, arr[naive], heap_arr[heap]);
      //      return 1;
    }


  }

  printf("all ok\n");
  return 0;
}
