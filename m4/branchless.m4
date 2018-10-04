include(common.m4)dnl
define(`step', `ret -= (arr[ret - $1] >= target) ? $1 : 0')dnl
define(`steps', `ifelse($1, 1, //end_of_branches, step(eval($1 / 2));
  `steps(eval($1 / 2))')')dnl
#pragma once
#include "data.h"

int branchless_search (float target) {
  int ret = size_array - 1;

  steps(eval(size_array + 1))

  return ret;
}

