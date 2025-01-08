#include <iostream>
#include <vector>
#include "array.h"

int ArraySolutions ::moreThanHalf(std ::vector<int> vec)
{
    int max_element = vec[0];
    int count = 1;
    int size = vec.size() - 1;
    for (int i = 0; i <= size; i++)
    {
        int element = vec[i];
        if (element == max_element)
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            /// Update the max element
            /// And the count should be 1
            max_element = element;
            count = 1;
        }
    }

    return max_element;
}
