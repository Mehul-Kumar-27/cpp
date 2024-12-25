#include <iostream>
#include <vector>
#include "custom/customSorting.h"
int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(5);
    v.push_back(40);
    v.push_back(24);
    int n = v.size() - 1;
    for (int i = 0; i < n; i++)
    {
        int minIndex = findMinIndex(v, i);
        std ::swap(v[i], v[minIndex]);
    }

    for (int i = 0; i < n; i++)
    {
        std ::cout << v[i] << ',';
    }
    std :: cout << std :: endl;

    return 0;
}
