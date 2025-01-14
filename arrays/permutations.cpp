#include <iostream>
#include <vector>
#include "array.h"

void generatePermutations(std ::vector<bool> &taken, std ::vector<int> &temp, std ::vector<int> &vec, std ::vector<std ::vector<int>> &permutations)
{
    if (temp.size() == vec.size())
    {
        permutations.push_back(temp);
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (taken[i] == false)
        {
            taken[i] = true;
            temp.push_back(vec[i]);
            generatePermutations(taken, temp, vec, permutations);
            taken[i] = false;
            temp.pop_back();
        }
    }

    return;
}

// This function would generate all the permutations for this vector array
std ::vector<std ::vector<int>> ArraySolutions ::allPermutations(std ::vector<int> &vec)
{
    std ::vector<std ::vector<int>> permutations;

    std ::vector<int> temp;
    int size = vec.size() - 1;
    std ::vector<bool> taken(size + 1, false);
    generatePermutations(taken, temp, vec, permutations);

    return permutations;
}


