#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/naive.h"
#include "../include/naive_alt.h"
#include "../include/cmov.h"
#include "../include/branchless.h"
#include "../include/code_gen.h"
#include "../include/code_gen_ternary.h"
#include "../include/heap.h"


int main() {
  int count = 0;
  struct timeval tval_start, tval_result;
  struct timeval naive_after, naive_alt_after, cmov_after,
    branchless_after, code_gen_after, code_gen_ternary_after,
    heap_after;
  gettimeofday(&tval_start, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += naive_search(random_float);
  }
  gettimeofday(&naive_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += naive_alt_search(random_float);
  }
  gettimeofday(&naive_alt_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += cmov_search(random_float);
  }
  gettimeofday(&cmov_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += branchless_search(random_float);
  }
  gettimeofday(&branchless_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += code_gen_search(random_float);
  }
  gettimeofday(&code_gen_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += code_gen_ternary_search(random_float);
  }
  gettimeofday(&code_gen_ternary_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += heap_search(random_float);
  }
  gettimeofday(&heap_after, NULL);

  // PRINTING RESULTS
  printf("number_of_floats = %d\n", NUM_FLOATS);
  printf("number_of_searches = %d\n", NUM_SEARCHES);
  timersub(&naive_after, &tval_start, &tval_result);
  printf("naive_search_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&naive_alt_after, &naive_after, &tval_result);
  printf("naive_alt_search_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&cmov_after, &naive_alt_after, &tval_result);
  printf("cmov_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&branchless_after, &cmov_after, &tval_result);
  printf("branchless_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&code_gen_after, &branchless_after, &tval_result);
  printf("code_gen_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&code_gen_ternary_after, &code_gen_after, &tval_result);
  printf("code_gen_ternary_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&heap_after, &code_gen_ternary_after, &tval_result);
  printf("heap_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  printf("count = %d\n", count);
}



