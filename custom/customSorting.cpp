#include <iostream>
#include <vector>
#include <algorithm>

bool minLogic(int a, int b)
{
    return a > b;
}

bool maxLogic(int a, int b)
{
    return a < b;
}

// This function takes in the vector and the index, and finds the minimum element's index
int findMinIndex(const std::vector<int> &vec, int index)
{
    auto minIt = std::min_element(vec.begin() + index, vec.end(), minLogic);
    return std::distance(vec.begin() + index, minIt);
}

int findMaxIndex(const std::vector<int> &vec, int index)
{
    auto maxIt = std::max_element(vec.begin() + index, vec.end(), maxLogic);
    return std::distance(vec.begin() + index, maxIt);
}
