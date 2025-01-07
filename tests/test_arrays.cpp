#include "gtest/gtest.h"
#include "../arrays/array.h"

// Global vector of test cases
std::vector<std::pair<std::vector<int>, std::pair<int, int>>> testCases = {
    {{2, 7, 11, 15}, {0, 1}}, // Simple input
};

TEST(TwoSumTest, GlobalTestCases)
{
    ArraySolutions solver;

    for (const auto &testCase : testCases)
    {
        const auto &nums = testCase.first;
        const auto &expectedIndices = testCase.second;
        int target = nums[expectedIndices.first] + nums[expectedIndices.second];

        std::vector<int> result = solver.twoSum(nums, target);
        if (expectedIndices.first == -1 && expectedIndices.second == -1)
        {
            EXPECT_EQ(result.size(), 2);
        }
        else
        {
            EXPECT_EQ(result.size(), 2);
            EXPECT_TRUE((result == std::vector<int>{expectedIndices.first, expectedIndices.second} ||
                         result == std::vector<int>{expectedIndices.second, expectedIndices.first}));
        }
    }
}
