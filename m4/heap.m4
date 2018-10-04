include(common.m4)dnl
define(`step', `i = (target > heap_arr[i]) ? (i * 2 + 1) : (i * 2);')dnl
define(`steps', `ifelse($1, 1, // end_of_levels, step
  `steps(eval($1 / 2))')')dnl
#pragma once
#include "heap_data.h"

int heap_search(float target) {
  int i = 1;
  steps(size_array)

  return i;
}
