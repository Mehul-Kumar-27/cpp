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

int partition(std ::vector<int> &v, int low, int high, int mid)
{
    // First make sure that the value at index mid is at right postion between the low and the high
    // Count the number of small elements present in the array
    int val = v[mid];
    int count = 0;

    for (int i = low; i <= high; i++)
    {
        if (v[i] < val)
        {
            count++;
        }
    }

    // now move the mid element to the low + count position
    int position = low + count;
    std ::swap(v[mid], v[position]);

    // Now make sure that all the elements to the right or position are bigger and on the left are smaller
    int i = low;
    int j = high;

    while (i <= j)
    {
        while (i < position)
        {
            if (v[i] > val)
            {
                break;
            }
            i++;
        }

        while (j > position)
        {
            if (v[j] < val)
            {
                break;
            }
            j--;
        }

        if (i < position && j > position)
        {
            std ::swap(v[i], v[j]);
        }
        i++;
        j--;
    }
    return position;
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

        // swap the element at this index with the min index
        std::swap(v[i], v[min_index]);
    }
}

void bubbleSort(std ::vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
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
            break;
        }
    }
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
}

// sorts the vector using quick sort
void quickSort(std ::vector<int> &v, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    int p = partition(v, low, high, mid);

    quickSort(v, low, p - 1);
    quickSort(v, p + 1, high);
    return;
}

void merge(std ::vector<int> &v, int low, int mid, int high)
{
    // Create the copy of the vector
    std ::vector<int> temp = v;

    // Now start the two pointers for the two sorted vectors
    int p1 = low;
    int p2 = mid + 1;
    int p3 = low;
    while (p1 <= mid && p2 <= high)
    {
        // find which value is smaller currently
        if (temp[p1] < temp[p2])
        {
            v[p3] = temp[p1];
            p1++;
        }
        else
        {
            v[p3] = temp[p2];
            p2++;
        }
        p3++;
    }

    // Remaining Part
    while (p1 <= mid)
    {
        v[p3] = temp[p1];
        p1++;
        p3++;
    }

    while (p2 <= high)
    {
        v[p3] = temp[p2];
        p2++;
        p3++;
    }
}

void mergeSort(std ::vector<int> &v, int low, int high)
{
    /// Base Case
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;

    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
