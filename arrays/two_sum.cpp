#include <iostream>
#include <vector>
#include <unordered_map>
#include "array.h"

std ::vector<int> ArraySolutions ::twoSum(const std ::vector<int> &vec, int target)
{
    std ::vector<int> ans;
    // Value, Index
    std ::unordered_map<int, int> mp;

    for (int i = 0; i < vec.size(); i++)
    {
        int element = vec[i];
        int remaining = target - element;
        // Now find if there is an element with value remaining
        if (mp.find(remaining) != mp.end())
        {
            // We have found out the remaining element
            ans.push_back(i);
            ans.push_back(mp[remaining]);
            break;
        }
        mp[element] = i;
    }

    if (ans.size() == 0)
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    return ans;
}
