#include <stdio.h>
#include <stdlib.h>

int cmp_float(const void * elem1, const void * elem2) {
  if(*(float*)elem1 < *(float*)elem2) {
    return -1;
  }
  return *(float*)elem1 > *(float*)elem2;
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
