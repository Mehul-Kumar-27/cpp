#include "gtest/gtest.h"
#include "../custom/customSorting.h"

TEST(SortingTest, FindMinIndex)
{
    std ::vector<int> vec = {5, 2, 9, 1, 3, -1};
    EXPECT_EQ(findMinIndex(vec, 0), 5);
    EXPECT_EQ(findMinIndex(vec, 3), 5);

    std ::vector<int> v = {-1};
    EXPECT_EQ(findMinIndex(v, 0), 0);
}

TEST(SortingTest, FindMaxIndex)
{
    std ::vector<int> vec = {5, 2, 9, 1, 3, -1};
    EXPECT_EQ(findMaxIndex(vec, 0), 2);
    EXPECT_EQ(findMaxIndex(vec, 3), 4);

    std ::vector<int> v = {-1};
    EXPECT_EQ(findMaxIndex(v, 0), 0);
}

// Helper function to test whether the vector is sorted
bool isSorted(const std ::vector<int> vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        if (vec[i] < vec[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Test suite for sorting algorithms
TEST(SortingTest, SelectionSortTest)
{
    std::vector<std::vector<int>> testVectors = {
        {},              // Empty vector
        {1},             // Single element
        {1, 2, 3, 4, 5}, // Already sorted
        {5, 4, 3, 2, 1}, // Reverse sorted
        {9, 5, 1, 3, 7}, // Random order
        {1, 1, 1, 1, 1, 1}};

    for (auto &vec : testVectors)
    {
        selectionSort(vec);
        EXPECT_TRUE(isSorted(vec)) << "The vector is not sorted after selectionSort.";
    }
}

TEST(SortingTest, BubbleSortTest)
{
    std::vector<std::vector<int>> testVectors = {
        {},              // Empty vector
        {1},             // Single element
        {1, 2, 3, 4, 5}, // Already sorted
        {5, 4, 3, 2, 1}, // Reverse sorted
        {9, 5, 1, 3, 7}, // Random order
        {1, 1, 1, 1, 1, 1}};

    for (auto &vec : testVectors)
    {
        bubbleSort(vec);
        EXPECT_TRUE(isSorted(vec)) << "The vector is not sorted after bubbleSort.";
    }
}

TEST(SortingTest, InsertionSortTest)
{
    std::vector<std::vector<int>> testVectors = {
        {},              // Empty vector
        {1},             // Single element
        {1, 2, 3, 4, 5}, // Already sorted
        {5, 4, 3, 2, 1}, // Reverse sorted
        {9, 5, 1, 3, 7}, // Random order
        {1, 1, 1, 1, 1, 1}};

    for (auto &vec : testVectors)
    {
        insertionSort(vec);
        EXPECT_TRUE(isSorted(vec)) << "The vector is not sorted after insertionSort.";
    }
}

TEST(SortingTest, QuickSortSortTest)
{
    std::vector<std::vector<int>> testVectors = {
        {},              // Empty vector
        {1},             // Single element
        {1, 2, 3, 4, 5}, // Already sorted
        {5, 4, 3, 2, 1}, // Reverse sorted
        {9, 5, 1, 3, 7}};

    for (auto &vec : testVectors)
    {
        quickSort(vec);
        if (!isSorted(vec))
        {
            std::ostringstream oss;
            for (const auto &val : vec)
            {
                oss << val << " ";
            }
            ADD_FAILURE() << "The vector is not sorted after quickSort: " << oss.str();
        }
        EXPECT_TRUE(isSorted(vec));
    }
}
