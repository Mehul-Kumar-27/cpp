// array.h
#ifndef ARRAY_H
#define ARRAY_H

#include <vector>
#include <iostream>
#include <unordered_map>

class ArraySolutions
{
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target);
    void dutchNationalFlag(std ::vector<int> &vec);
    int moreThanHalf(std ::vector<int> vec);
    long long kadaneAlgorithm(std ::vector<int> vec);
    std ::vector<std ::vector<int>> allPermutations(std ::vector<int> &vec);
    int longestSubsequence(std ::vector<int> vec);
};

#endif // ARRAY_H
