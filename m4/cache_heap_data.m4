include(common.m4)dnl
#pragma once

float cache_heap_arr[] = {
syscmd(../build/gen_cache_heap.exe size_power cache_depth)};
