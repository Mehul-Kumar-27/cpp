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
    return std::distance(vec.begin(), maxIt);
}

void printVector(std ::vector<int> v)
{
    std::cout << "Sorted vector: ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
// Selection Sorting algorithm
void selectionSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // from this index to the last index find the minimum element index
        int min_index = findMinIndex(v, i);

        std::cout << "For round " << i << " min value is " << v[min_index] << " on index: " << min_index << std::endl;

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

    printVector(v);
}

void bubbleSort(std ::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std ::cout << "Round " << i << " running" << std ::endl;
        bool isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                isSorted = false;
                std ::swap(v[j], v[j + 1]);
            }
        }
        if (isSorted)
        {
            std ::cout << "Vector is Sorted" << std ::endl;
            break;
        }
    }

    printVector(v);
}

void insertionSort(std ::vector<int> &v)
{
    // Consider the 0th index as already sorted
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        // Now search for the index where it should be places in the right array
        int j = i - 1;
        int temp = v[i];
        while (j >= 0)
        {
            if (v[j] > temp)
            {
                v[j + 1] = v[j];
            }
            else
            {
                // the element at the j position is either smaller or equal to or smaller than the temp
                // we want to place the temp element just before the j
                break;
            }
            j--;
        }
        v[j + 1] = temp;
    }

    printVector(v);
}
