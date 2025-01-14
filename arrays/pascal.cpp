#include <iostream>
#include <vector>
#include "array.h"

using namespace std;

std ::vector<std::vector<int>> ArraySolutions ::pascalTriangle(int numRows)
{
    int rows = numRows - 1;
    vector<int> r1 = {1};
    vector<int> r2 = {1, 1};
    vector<vector<int>> ans;
    if(numRows == 0){
        return ans;
    }
    ans.push_back(r1);
    if (rows == 0)
    {
        return ans;
    }
    ans.push_back(r2);
    if (rows == 1)
    {
        return ans;
    }
    for (int i = 2; i <= rows; i++)
    {
        vector<int> row(i + 1, 1);
        vector<int> prev = ans[i - 1];
        for (int j = 1; j <= row.size() - 2; j++)
        {
            row[j] = prev[j] + prev[j - 1];
        }
        ans.push_back(row);
    }

    return ans;
}
