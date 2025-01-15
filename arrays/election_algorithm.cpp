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

std ::vector<int> ArraySolutions ::moreThanOneThird(std ::vector<int> &nums)
{
    int el1 = 0;
    int el2 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count1 == 0 && nums[i] != el2)
        {
            count1 = 1;
            el1 = nums[i];
        }
        else if (count2 == 0 && nums[i] != el1)
        {
            count2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    std ::vector<int> ans;
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == el1)
        {
            count1++;
        }
        else if (nums[i] == el2)
        {
            count2++;
        }
    }

    int min = (int)nums.size() / 3;
    if (count1 > min)
        ans.push_back(el1);
    if (count2 > min)
        ans.push_back(el2);

    sort(ans.begin(), ans.end());

    return ans;
}
