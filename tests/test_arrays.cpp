#include "gtest/gtest.h"
#include "../arrays/array.h"
#include "helpers.h"

TEST(ArrayQuestions, TwoSum)
{
    // Global vector of test cases
    std::vector<std::pair<std::vector<int>, std::pair<int, int>>> testCases = {
        {{2, 7, 11, 15}, {0, 1}}, // Simple input
    };
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

TEST(ArrayQuestions, DutchElectionAlgorithm)
{
    // Global vector of test cases
    std::vector<std::vector<int>> testCases = {
        {0, 1, 2},          // Already sorted
        {2, 1, 0},          // Reverse sorted
        {1, 0, 2},          // Random order
        {0, 0, 0},          // All 0s
        {1, 1, 1},          // All 1s
        {2, 2, 2},          // All 2s
        {0, 1, 0, 1, 2, 2}, // Mixed order
        {},                 // Empty array
        {0},                // Single element 0
        {1},                // Single element 1
        {2}                 // Single element 2
    };
    ArraySolutions solver;

    for (auto &testCase : testCases)
    {
        solver.dutchNationalFlag(testCase);
        EXPECT_TRUE(isSorted(testCase)) << "The vector is not sorted correctly.";
    }
}

TEST(ArrayQuestions, MoreThanHalf)
{
    // Global vector of test cases
    std::vector<std::pair<std::vector<int>, int>> testCases = {
        {{0, 0, 2}, 0},                         // Already sorted
        {{0, 1, 0}, 0},                         // Reverse sorted
        {{1, 3, 5, 0, 0, 0, 0}, 0},             // Random order
        {{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5}, 5}, // All 0s
        {{0}, 0},                               // Single element 0
        {{1}, 1},                               // Single element 1
        {{2}, 2}                                // Single element 2
    };

    ArraySolutions solver;
    for (auto &testCase : testCases)
    {
        const auto vec = testCase.first;
        const auto ans = testCase.second;

        EXPECT_EQ(solver.moreThanHalf(vec), ans);
    }
}
