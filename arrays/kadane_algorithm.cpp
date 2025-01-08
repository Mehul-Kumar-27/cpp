#include <iostream>
#include <vector>
#include "array.h"

long long ArraySolutions::kadaneAlgorithm(std::vector<int> vec) {
    long long global_max = LLONG_MIN; // Use LLONG_MIN for long long type
    long long current_max = 0;
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        long long element = vec[i];
        current_max = std::max(element, current_max + element);
        global_max = std::max(global_max, current_max);
    }
    return global_max;
}
