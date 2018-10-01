#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/naive.h"
#include "../include/branchless.h"

int main() {

  struct timeval tval_before, tval_after, tval_result;
  gettimeofday(&tval_before, NULL);

  int count = 0;
  for (int i = 0; i < NUM_SEARCHES; i++) {
    float random_float = (float) rand() / (float) (RAND_MAX / 10000);
    count += naive_search(random_float);
  }

  gettimeofday(&tval_after, NULL);
  timersub(&tval_after, &tval_before, &tval_result);
  printf("Count: %d\n", count);
  printf("Time elapsed: %ld.%06ld\n", (long int)tval_result.tv_sec, (long int)tval_result.tv_usec);
}



