#include <gtest/gtest.h>
#include <cstdio>

extern "C" {
    #include "c_vector.h"
}

class VectorTest : public ::testing::Test {
protected:
    Vector* v;

    void SetUp() override {
        v = vector_create(4, sizeof(int)); 
    }

    void TearDown() override {
        if (v) vector_destroy(v);
    }
};

TEST_F(VectorTest, Initialization) {
    ASSERT_TRUE(v != nullptr);
    EXPECT_EQ(vector_get_size(v), 0);
    EXPECT_EQ(vector_get_capacity(v), 4); 
    EXPECT_EQ(vector_get_item_size(v), sizeof(int));
}

TEST_F(VectorTest, PushBackLogic) {
    for(int i = 0; i < 4; i++) {
        vector_push_back(v, &i);
    }
    
    EXPECT_EQ(vector_get_size(v), 4);
    EXPECT_EQ(vector_get_capacity(v), 4);

    int val = 99;
    vector_push_back(v, &val); 
    
    EXPECT_EQ(vector_get_size(v), 5);
    EXPECT_EQ(vector_get_capacity(v), 8); // Doubled from 4
}

TEST_F(VectorTest, DataIntegrity) {
    int input[] = {10, 20, 30};
    for(int i = 0; i < 3; i++) {
        vector_push_back(v, &input[i]);
    }

    for(int i = 0; i < 3; i++) {
        int output = 0;
        vector_get_element(v, i, &output);
        EXPECT_EQ(output, input[i]);
    }
}

TEST_F(VectorTest, PopBackLogic) {
    for(int i = 0; i < 5; i++) {
        vector_push_back(v, &i);
    }
    EXPECT_EQ(vector_get_capacity(v), 8);
    EXPECT_EQ(vector_get_size(v), 5);

    vector_pop_back(v, nullptr);
    EXPECT_EQ(vector_get_capacity(v), 8);

    vector_pop_back(v, nullptr); 
    EXPECT_EQ(vector_get_capacity(v), 8);

    int popped_val = 0;
    vector_get_element(v, 2, &popped_val);
    vector_pop_back(v, nullptr); 

    EXPECT_EQ(vector_get_size(v), 2);
    EXPECT_EQ(vector_get_capacity(v), 4);
}