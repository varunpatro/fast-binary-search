include(common.m4)dnl
define(`inner_step', `i = outer * eval(2 ** cache_depth) + inner; inner *= 2; inner += (target > cache_heap_arr[i]);')dnl
define(`inner_loop', `ifelse($1, 1,, inner_step
  `inner_loop(eval($1 - 1))')')dnl
define(`outer_step', `outer *= eval(2 ** cache_depth); outer += 1; outer += (inner - eval(2 ** (cache_depth - 1))) * 2 + (target > cache_heap_arr[i]); inner = 1;')dnl
define(`outer_loop', `ifelse($1, 1,, 
  outer_step
  inner_loop(cache_depth) 
  `outer_loop(eval($1 - 1))')')dnl
#pragma once
#include "cache_heap_data.h"

int cache_heap_search(float target) {
  int outer = 0, inner = 1, i = 0;

  inner_loop(cache_depth)
  outer_loop(eval(size_power / cache_depth))
  return outer * 4 + inner;
}
