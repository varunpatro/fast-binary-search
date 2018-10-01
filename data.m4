include(common.m4)dnl
#pragma once
format(`#define NUM_FLOATS %d', size_array)
format(`#define MAX_FLOAT %d', max_float)
format(`#define NUM_SEARCHES %d', num_searches)

int search(float);

float arr[] = {
syscmd(./gen_random_floats defn(`size_array'))};


