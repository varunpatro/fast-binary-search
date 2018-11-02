#include<vector> 
#include<iostream>
#include<cmath>
#include<queue>

#include "../include/heap_data.h"

using namespace std;

vector<int> generate_index(int size, int cache_height) {
    vector<int> cache_heap;
    cache_heap.push_back(0);

    queue<int> next_element;
    next_element.push(1);
    while(!next_element.empty()) {
        int top = next_element.front();
        next_element.pop();

        if (top >= size) break;

        for (int i = 0; i < cache_height; i++) {
            int base = top * pow(2, i);
            int num_elements = pow(2, i);

            for (int j = 0; j < num_elements; j++) {
                cache_heap.push_back(base + j);
            }
        }

        for (int i = 0; i < pow(2, cache_height); i++) {
            next_element.push(top * pow(2, cache_height) + i);
        }
    }

    return cache_heap;
}

int main(int argc, char** argv) 
{
    int size = pow(2, stoi(argv[1]));
    int cache_height = stoi(argv[2]);
    int cache_block_size = 1 << cache_height;
    vector<int> output = generate_index(size, cache_height);
    int n = 0;
    for (int i = 1; i < output.size(); i++) {
        if (n % (cache_block_size - 1) == 0) {
        	printf("%f,\n", heap_arr[0]);
            // cout << 0 << endl;
        }
        n = (n + 1) % (cache_block_size - 1);
        printf("%f,\n", heap_arr[output[i]]);
        // cout<< output[i] << endl;
    }
}
