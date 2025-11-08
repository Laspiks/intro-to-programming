extern "C" {
#include "array_utils.h"
}

#include <gtest/gtest.h>
// gmock not required here

#include <limits.h>

// Test fixture 
class FillArrayFromFileTest : public ::testing::Test {
protected:
    static const int size = 3;
    void** array;

    // Allocate array before each test
    void SetUp() override {
        array = (void**)malloc(size * sizeof(void*));
        for (int i = 0; i < size; i++) {
            array[i] = malloc(size * sizeof(int));
        }
    }

    // Free array after each test
    void TearDown() override {
        for (int i = 0; i < size; i++) {
            free(array[i]);
        }
        free(array);
    }
};

TEST_F(FillArrayFromFileTest, HappyCaseWithValidFile) {
    // ToDo: create 
    // Capture stdout to verify printed output
    testing::internal::CaptureStdout();

    // Call the function
    int res = fill_2d_array_from_file(array, size, "./tests/tests.txt");
    
    // Get captured output
    std::string output = testing::internal::GetCapturedStdout();

    // Verify function return value
    EXPECT_EQ(res, 0);

    // Verify printed output contains expected strings
    EXPECT_NE(output.find("Array filled from file"), std::string::npos);
    EXPECT_NE(output.find("./tests/tests.txt"), std::string::npos);
}

TEST_F(FillArrayFromFileTest, ErrorWhenFileMissing) {
    // Capture stderr (error messages)
    testing::internal::CaptureStderr();

    // Call function with a file that doesn't exist
    int res = fill_2d_array_from_file(array, size, "nonexistent_file.txt");

    // Get captured output
    std::string output = testing::internal::GetCapturedStderr();

    // Check return value
    EXPECT_EQ(res, -1);

    // Check printed error message
    EXPECT_NE(output.find("Error: cannot open file"), std::string::npos);
}

// ToDo: add more test cases (at least 2) to cover other possible scenarios