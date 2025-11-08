extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>
#include <limits.h>

// Convert assert-based tests to gtest TEST cases

TEST(BinarySearchTest, EmptyArray) {
    // For empty array, pass nullptr and size 0
    const int* arr = nullptr;
    EXPECT_EQ(binary_search(arr, 0, 5), -1);
}

TEST(BinarySearchTest, OneElement) {
    const int arr[] = {42};
    int n = 1;
    EXPECT_EQ(binary_search(arr, n, 42), 0);
    EXPECT_EQ(binary_search(arr, n, 43), -1);
    EXPECT_EQ(binary_search(arr, n, 41), -1);
}

TEST(BinarySearchTest, TwoElements) {
    const int arr[] = {10, 20};
    int n = 2;
    EXPECT_EQ(binary_search(arr, n, 10), 0);
    EXPECT_EQ(binary_search(arr, n, 20), 1);
    EXPECT_EQ(binary_search(arr, n, 15), -1);
}

TEST(BinarySearchTest, ThreeElements) {
    const int arr[] = {5, 15, 25};
    int n = 3;
    EXPECT_EQ(binary_search(arr, n, 5), 0);
    EXPECT_EQ(binary_search(arr, n, 15), 1);
    EXPECT_EQ(binary_search(arr, n, 25), 2);
    EXPECT_EQ(binary_search(arr, n, 10), -1);
}

TEST(BinarySearchTest, MultipleElementsSequentialCheck) {
    const int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = 7;
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(binary_search(arr, n, arr[i]), i);
    }
    EXPECT_EQ(binary_search(arr, n, 3), -1);
}

TEST(BinarySearchTest, LargerEvenOddSets) {
    const int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = 10;
    for (int i = 0; i < n; i++) {
        EXPECT_EQ(binary_search(arr, n, arr[i]), i);
    }
    EXPECT_EQ(binary_search(arr, n, 2), -1);
}

TEST(BinarySearchTest, SearchIntMax) {
    const int arr[] = {0, 1, 2, 5, 10, INT_MAX};
    int n = sizeof(arr) / sizeof(arr[0]);
    EXPECT_EQ(binary_search(arr, n, INT_MAX), 5);
    EXPECT_EQ(binary_search(arr, n, INT_MAX - 1), -1);
}

TEST(BinarySearchTest, SearchIntMin) {
    const int arr[] = {INT_MIN, -10, -5, 0, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    EXPECT_EQ(binary_search(arr, n, INT_MIN), 0);
    EXPECT_EQ(binary_search(arr, n, INT_MIN + 1), -1);
}

TEST(BinarySearchTest, DuplicateElementsFirstOccurrence) {
    const int arr[] = {1, 3, 5, 5, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, n, 5);
    // The implementation may return any index of a matching element.
    // Accept any valid index where arr[result] == 5 and result in [2,4].
    EXPECT_NE(result, -1);
    EXPECT_GE(result, 2);
    EXPECT_LE(result, 4);
    EXPECT_EQ(arr[result], 5);
}

TEST(BinarySearchTest, AllElementsSame) {
    const int arr[] = {5, 5, 5, 5, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binary_search(arr, n, 5);
    // Any index within range is acceptable as long as it points to the target
    EXPECT_NE(result, -1);
    EXPECT_GE(result, 0);
    EXPECT_LT(result, n);
    EXPECT_EQ(arr[result], 5);
}
