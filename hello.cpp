#include <iostream>
#include <vector>
#include "custom/customSorting.h"
int main()
{
    std::vector<int> v = {5, 6, 7, 8, 9, 1, 2, 0, -99, -111111, 1, 1};

    selectionSort(v);
    return 0;
}
