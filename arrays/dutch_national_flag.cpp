
#include <iostream>
#include <vector>
#include "array.h"

/// @brief Sorts the input vector using the Dutch National Flag algorithm.
/// The algorithm sorts an array of 0s, 1s, and 2s in linear time complexity.
/// @param vec A reference to the vector of integers to be sorted.
void ArraySolutions ::dutchNationalFlag(std ::vector<int> &vec)
{
    int low = 0;
    int mid = 0;
    int high = vec.size() - 1;

    /// 0 to low - 1 -> 0
    /// low to mid -1 -> 1
    /// mid to high -> unsorted
    /// high+1 to n-1 -> 2

    while (mid <= high)
    {
        int element = vec[mid];
        if (element == 0)
        {
            std ::swap(vec[low], vec[mid]);
            low++;
            mid++;
        }
        else if (element == 1)
        {
            mid++;
        }
        else
        {
            std ::swap(vec[mid], vec[high]);
            high--;
        }
    }
}
