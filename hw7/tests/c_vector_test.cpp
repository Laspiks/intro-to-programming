extern "C" {
#include "../include/c_vector.h"
}

#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

TEST(CVectorTest, CreateAndFree)
{
    int* v = create_vector(3);
    ASSERT_NE(v, nullptr);
    // initial values are zero
    EXPECT_EQ(v[0], 0);
    EXPECT_EQ(v[1], 0);
    EXPECT_EQ(v[2], 0);
    free_vector(v);
}

TEST(CVectorTest, PushBackAndSize)
{
    int size = 0;
    int* v = NULL;
    v = push_back(v, &size, 10);
    ASSERT_NE(v, nullptr);
    EXPECT_EQ(size, 1);
    EXPECT_EQ(v[0], 10);

    v = push_back(v, &size, 20);
    EXPECT_EQ(size, 2);
    EXPECT_EQ(v[1], 20);

    // push several to force reallocation
    for (int i = 0; i < 20; ++i) v = push_back(v, &size, i);
    EXPECT_EQ(size, 22);
    free_vector(v);
}

TEST(CVectorTest, PopBackBehavior)
{
    int size = 0;
    int* v = NULL;
    v = push_back(v, &size, 5);
    v = push_back(v, &size, 6);
    EXPECT_EQ(size, 2);
    int x = pop_back(v, &size);
    EXPECT_EQ(x, 6);
    EXPECT_EQ(size, 1);
    x = pop_back(v, &size);
    EXPECT_EQ(x, 5);
    EXPECT_EQ(size, 0);
    // popping empty returns 0
    x = pop_back(v, &size);
    EXPECT_EQ(x, 0);
    free_vector(v);
}


TEST(CVectorTest, PrintNoCrash)
{
    int* v = create_vector(2);
    v[0] = 1; v[1] = 2;
    print(v, 2);
    print(NULL, 0);
    free_vector(v);
}