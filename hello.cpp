#include <iostream>
#include <vector>
#include "custom/customSorting.h"
int main()
{
    std::vector<int> v = {99999, -1, 0, 1, 2, 3, 4, 5, -8, 6, 1, 0, -11, 32};

    insertionSort(v);
    return 0;
}
