#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/naive.h"
#include "../include/branchless.h"

int main() {
  int count = 0;
  struct timeval tval_result;
  struct timeval naive_before, naive_after;
  struct timeval branchless_after;

  gettimeofday(&naive_before, NULL);
  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += naive_search(random_float);
  }
  gettimeofday(&naive_after, NULL);

  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += naive_search(random_float);
  }
  gettimeofday(&branchless_after, NULL);

  // PRINTING RESULTS
  printf("number of floats = %d\n", NUM_FLOATS);
  printf("number of searches = %d\n", NUM_SEARCHES);
  timersub(&naive_after, &naive_before, &tval_result);
  printf("naive_search_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  timersub(&branchless_after, &naive_after, &tval_result);
  printf("branchless_elapsed = %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);

  printf("count = %d\n", count);
}



