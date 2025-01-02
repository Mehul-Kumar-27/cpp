#include <iostream>
#include <vector>
#include <algorithm>

// This function takes in the vector and the index, and finds the minimum element's index
int findMinIndex(const std::vector<int> &vec, int index)
{
    auto minIt = std::min_element(vec.begin() + index, vec.end());
    return std::distance(vec.begin(), minIt);
}

int findMaxIndex(const std::vector<int> &vec, int index)
{
    auto maxIt = std::max_element(vec.begin() + index, vec.end());
    return std::distance(vec.begin() + index, maxIt);
}

// Selection Sorting algorithm
void selectionSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // from this index to the last index find the minimum element index
        int min_index = findMinIndex(v, i);

        std::cout << "For round " << i << " min value is " << v[min_index] << std::endl;

        // swap the element at this index with the min index
        std::swap(v[i], v[min_index]);

        // Print vector after this round
        std::cout << "Vector after round " << i << ": ";
        for (int j = 0; j < v.size(); j++)
        {
            std::cout << v[j] << " ";
        }
        std::cout << std::endl;
    }

    // Print the sorted vector
    std::cout << "Sorted vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
