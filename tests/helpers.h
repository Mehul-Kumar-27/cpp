#ifndef HELPERS_H

#define HELPERS_H
#include <vector>

// Helper function to test whether the vector is sorted
bool isSorted(const std::vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[i - 1])
        {
            return false;
        }
    }
    return true;
}
#endif
