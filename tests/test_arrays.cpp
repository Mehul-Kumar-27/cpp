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

TEST(ArrayQuestions, KadaneAlgorithm)
{
    std::vector<std::pair<std::vector<int>, long long>> kadaneTestCases = {
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},           // Standard case
        {{1}, 1},                                       // Single element
        {{5, 4, -1, 7, 8}, 23},                         // All positive with one negative
        {{-1, -2, -3, -4}, -1},                         // All negative
        {{INT_MAX, -1, INT_MAX}, 2147483647LL * 2 - 1}, // Including INT_MAX
        {{INT_MIN, INT_MIN, INT_MIN}, INT_MIN},         // All INT_MIN
        {{0, 0, 0, 0}, 0},                              // All zeros
        {{-1, 2, 3, -5, 4, 6, -1}, 10}};
    ArraySolutions solver;

    for (const auto &testCase : kadaneTestCases)
    {
        const auto &vec = testCase.first;
        const auto &expectedAns = testCase.second;

        long long result = solver.kadaneAlgorithm(vec);
        EXPECT_EQ(result, expectedAns) << "Failed for vector: " << ::testing::PrintToString(vec);
    }
}

TEST(ArrayQuestions, GenerateAllPermutations)
{
    // Global vector of test cases
    std::vector<std::vector<int>> testCases = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6, 7},
        {1, 2, 3, 4, 5, 6, 7, 8}};
    ArraySolutions solver;

    for (const auto &testCase : testCases)
    {
        std ::vector<int> test_vector = testCase;
        auto start = std::chrono::high_resolution_clock::now();
        std ::vector<std ::vector<int>> permutations = solver.allPermutations(test_vector);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Time taken to generate permutations: " << duration.count() << " seconds" << std::endl;
        std ::cout << "Number of Permutaions Genereated " << permutations.size() << std::endl;
    }
}

TEST(ArrayQuestions, LongestSubSequenceOfConsecutive)
{
    std ::vector<std ::pair<std ::vector<int>, int>> testCases = {
        {{100, 4, 200, 1, 3, 2}, 4},          // The sequence 1, 2, 3, 4
        {{0, 3, 7, 2, 5, 8, 4, 6, 0, 1}, 9},  // The sequence 0 to 8
        {{1, 2, 0, 1}, 3},                    // The sequence 0, 1, 2
        {{9, 1, 4, 7, 3, -1, 0, 5, 8, 6}, 7}, // The sequence -1 to 5
        {{10, 20, 30, 40}, 1},                // No consecutive sequence, all individual
        {{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9},     // Continuous sequence
        {{5, 6, 2, 1, 4}, 3},                 // The sequence 1 to 3
        {{}, 0},                              // Empty input
        {{1}, 1},                             // Single element
        {{1, 1, 1, 1}, 1},                    // Repeated single element
        {{1, 2, 2, 3, 3, 4, 4, 5}, 5},        // Duplicate entries, sequence 1 to 5
    };
    ArraySolutions solver;

    for (const auto &testCase : testCases)
    {
        const auto &vec = testCase.first;
        const auto &expectedAns = testCase.second;

        long long result = solver.longestSubsequence(vec);
        EXPECT_EQ(result, expectedAns) << "Failed for vector: " << ::testing::PrintToString(vec);
    }
}
