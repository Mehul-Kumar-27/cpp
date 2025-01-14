#include <iostream>
#include <vector>
#include <unordered_set>
#include "array.h"

int ArraySolutions ::longestSubsequence(std ::vector<int> vec)
{
    std ::unordered_set<int> st;
    auto size = vec.size() - 1;
    if (size == -1)
    {
        return 0;
    }
    for (int i = 0; i <= size; i++)
    {
        st.insert(vec[i]);
    }

    // Iterate through the set
    std ::unordered_set<int>::iterator it = st.begin();
    int ans = 1;

    while (it != st.end())
    {
        // if there is an element that is less than this value in the set then we would ignore this element
        // Better to start counting form the starting point of the set
        int element = *it;
        int less_element = element - 1;
        if (st.find(less_element) == st.end())
        {
            // if there is no element less than this for this subsequence it may be the starting poing of the sequence
            bool end = false;
            int count = 1;
            while (!end)
            {
                if (st.find(element + 1) != st.end())
                {
                    count++;
                    element = element + 1;
                }
                else
                {
                    /// no element greater than this
                    ans = std ::max(ans, count);
                    end = true;
                }
            }
        }
        it++;
    }

    return ans;
}
