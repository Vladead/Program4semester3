#include <gtest/gtest.h>
#include "ArrayAlgorithms.h"


TEST(ArrayAlgorithms, BinarySearch_test) {
    int testArray[5] {1, 2, 3, 4, 5};
    ASSERT_EQ(0, BinarySearch(testArray, 5, 1));
    ASSERT_EQ(4, BinarySearch(testArray, 5, 5));
    ASSERT_EQ(2, BinarySearch(testArray, 5, 3));

    ASSERT_ANY_THROW(BinarySearch(testArray, 0, 4));
}

TEST(ArrayAlgorithms, QuickSort_test) {
    int testArray[5] {4, 2, 5, 1, 3};
    QuickSort(testArray, 0, 4);
    ASSERT_EQ(1, testArray[0]);
    ASSERT_EQ(5, testArray[4]);
}

TEST(ArrayAlgorithms, InsertionSort_test) {
    int testArray[5] {4, 2, 5, 1, 3};
    InsertionSort(testArray, 5);
    ASSERT_EQ(1, testArray[0]);
    ASSERT_EQ(5, testArray[4]);

    ASSERT_ANY_THROW(InsertionSort(testArray, 0));
}

TEST(ArrayAlgorithms, TreeSort_test) {
    int testArray[5] {4, 2, 5, 1, 3};
    TreeSort(testArray, 5);
    ASSERT_EQ(5, testArray[0]);
    ASSERT_EQ(1, testArray[4]);

    ASSERT_ANY_THROW(TreeSort(testArray, 0));
}

TEST(ArrayAlgorithms, CountingSort_test) {
    char testArray[5] {'b', 'd', 'a', 'e', 'c'};
    CountingSort(testArray, 5);
    ASSERT_EQ('a', testArray[0]);
    ASSERT_EQ('e', testArray[4]);

    ASSERT_ANY_THROW(CountingSort(testArray, 0));
}