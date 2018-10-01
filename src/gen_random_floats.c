#include <stdio.h>
#include <stdlib.h>

int cmp_float (const void * a, const void * b) {
  return ( *(float*)a - *(float*)b );
}

int main(int argc, char** argv) {
  int n = atoi(argv[1]);
  float arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = (float) rand() / (float) (RAND_MAX / 10000);
  }

  qsort(arr, n, sizeof(float), cmp_float);

  for (int i = 0; i < n; i++) {
    printf("%f,\n", arr[i]);
  }

  return 0;
}
