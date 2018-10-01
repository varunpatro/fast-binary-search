
#pragma once
#include "data.h"

int search (float target) {
  int ret = 0;

  ret += (arr[ret + 4] <= target) ? 4 : 0;
  ret += (arr[ret + 2] <= target) ? 2 : 0;
  ret += (arr[ret + 1] <= target) ? 1 : 0;
  ret += (arr[ret + 0] <= target) ? 0 : 0;
  //end_of_branches

  return ret;
}

