extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>
#include <limits.h>

TEST(BinarySearchTest, EmptyArray) {
    int **arr = allocate_2d_array(5);
    EXPECT_TRUE(arr != NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
