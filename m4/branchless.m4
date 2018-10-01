include(common.m4)dnl
define(`step', `ret += (arr[ret + $1] <= target) ? $1 : 0')dnl
define(`steps', `ifelse($1, 0, //end_of_branches, step(eval($1 / 2));
  `steps(eval($1 / 2))')')dnl

#pragma once
#include "data.h"

int search (float target) {
  int ret = 0;

  steps(size_array)

  return ret;
}

