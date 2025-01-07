#include "gtest/gtest.h"
#include "../custom/customSorting.h"
#include "helpers.h"

// Global test vectors that can be used across all test cases
namespace
{
    const std::vector<std::vector<int>> TEST_VECTORS = {
        {},                                   // Empty vector
        {1},                                  // Single element
        {1, 2, 3, 4, 5},                      // Already sorted
        {5, 4, 3, 2, 1},                      // Reverse sorted
        {9, 5, 1, 3, 7},                      // Random order
        {1, 1, 1, 1, 1, 1},                   // All same elements
        {INT_MAX, INT_MIN},                   // Edge case with max and min integers
        {0, 0, 0, 1, 0, 0},                   // Multiple zeros with one different number
        {-5, -4, -3, -2, -1},                 // All negative numbers sorted
        {-1, -2, -3, -4, -5},                 // All negative numbers reverse sorted
        {2, -3, 4, -5, 6, -7},                // Mixed positive and negative
        {1, 2, 2, 2, 3, 3},                   // Duplicate elements
        {999999, 1000000, -1000000, -999999}, // Large numbers
        {1, 2, 3, 2, 1},                      // Mountain array
        {0},                                  // Single zero
        {INT_MIN},                            // Single minimum integer
        {INT_MAX}                             // Single maximum integer
    };
}

TEST(SortingTest, FindMinIndex)
{
    std::vector<int> vec = {5, 2, 9, 1, 3, -1};
    EXPECT_EQ(findMinIndex(vec, 0), 5);
    EXPECT_EQ(findMinIndex(vec, 3), 5);

    std::vector<int> v = {-1};
    EXPECT_EQ(findMinIndex(v, 0), 0);

    // Additional edge cases
    std::vector<int> allSame = {1, 1, 1, 1};
    EXPECT_EQ(findMinIndex(allSame, 0), 0);

    std::vector<int> extremes = {INT_MAX, INT_MIN, 0};
    EXPECT_EQ(findMinIndex(extremes, 0), 1);
}

TEST(SortingTest, FindMaxIndex)
{
    std::vector<int> vec = {5, 2, 9, 1, 3, -1};
    EXPECT_EQ(findMaxIndex(vec, 0), 2);
    EXPECT_EQ(findMaxIndex(vec, 3), 4);

    std::vector<int> v = {-1};
    EXPECT_EQ(findMaxIndex(v, 0), 0);

    // Additional edge cases
    std::vector<int> allSame = {1, 1, 1, 1};
    EXPECT_EQ(findMaxIndex(allSame, 0), 0);

    std::vector<int> extremes = {INT_MAX, INT_MIN, 0};
    EXPECT_EQ(findMaxIndex(extremes, 0), 0);
}

// Test suite for sorting algorithms
TEST(SortingTest, SelectionSortTest)
{
    for (auto vec : TEST_VECTORS)
    {
        std::vector<int> testVec = vec; // Create a copy to preserve original
        selectionSort(testVec);
        EXPECT_TRUE(isSorted(testVec)) << "The vector is not sorted after selectionSort.";
    }
}

TEST(SortingTest, BubbleSortTest)
{
    for (auto vec : TEST_VECTORS)
    {
        std::vector<int> testVec = vec;
        bubbleSort(testVec);
        EXPECT_TRUE(isSorted(testVec)) << "The vector is not sorted after bubbleSort.";
    }
}

TEST(SortingTest, InsertionSortTest)
{
    for (auto vec : TEST_VECTORS)
    {
        std::vector<int> testVec = vec;
        insertionSort(testVec);
        EXPECT_TRUE(isSorted(testVec)) << "The vector is not sorted after insertionSort.";
    }
}

TEST(SortingTest, QuickSortTest)
{
    for (auto vec : TEST_VECTORS)
    {
        std::vector<int> testVec = vec;
        if (!testVec.empty())
        {
            quickSort(testVec, 0, testVec.size() - 1);
        }
        EXPECT_TRUE(isSorted(testVec)) << "Vector is not sorted after quick sort";
    }
}

TEST(SortingTest, MergeSortTest)
{
    for (auto vec : TEST_VECTORS)
    {
        std::vector<int> testVec = vec;
        if (!testVec.empty())
        {
            mergeSort(testVec, 0, testVec.size() - 1);
        }
        EXPECT_TRUE(isSorted(testVec)) << "Vector is not sorted after merge sort";
    }
}
