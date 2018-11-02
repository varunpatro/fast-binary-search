include(common.m4)dnl
#pragma once
format(`#define NUM_DEPTH %d', size_power)
format(`#define NUM_FLOATS %d', size_array)
format(`#define MAX_FLOAT %d', max_float)
format(`#define NUM_SEARCHES %d', num_searches)

float arr[] = {
syscmd(../build/gen_random_floats.exe defn(`size_array'))};


