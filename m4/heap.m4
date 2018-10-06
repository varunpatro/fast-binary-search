include(common.m4)dnl
define(`step', `a = i * 2; a += (target > heap_arr[i]); i = a;')dnl
define(`steps', `ifelse($1, 1, // end_of_levels, step
  `steps(eval($1 / 2))')')dnl
#pragma once
#include "heap_data.h"

int heap_search(float target) {
  int a, i = 1;
  steps(size_array)

  return i;
}
