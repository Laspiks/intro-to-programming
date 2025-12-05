#include <gtest/gtest.h>
#include <cstdio>
#include "c_vector.h"

class VectorTest : public ::testing::Test {
protected:
    Vector* v;

    void SetUp() override {
        v = create_vector(4); // Request 4, expect cap 8
    }

    void TearDown() override {
        if (v) v->destroy(v);
    }
};

TEST_F(VectorTest, Initialization) {
    ASSERT_TRUE(v != nullptr);
    EXPECT_EQ(v->get_size(v), 0);
    EXPECT_EQ(v->get_capacity(v), 8); // 4 * 2
}

TEST_F(VectorTest, PushBackLogic) {
    for(int i=0; i<8; i++) {
        v->push_back(v, i);
    }
    // Capacity should still be 8
    EXPECT_EQ(v->get_size(v), 8);
    EXPECT_EQ(v->get_capacity(v), 8);

    // Trigger resize
    v->push_back(v, 99); 
    EXPECT_EQ(v->get_size(v), 9);
    EXPECT_EQ(v->get_capacity(v), 16); // Doubled from 8
}

TEST_F(VectorTest, PopBackLogic) {
    // Fill to 5 elements (Cap 8)
    for(int i=0; i<5; i++) v->push_back(v, i);
    
    // Pop down to 2 elements (2 is NOT < 8/4=2)
    v->pop_back(v); // Size 4
    v->pop_back(v); // Size 3
    v->pop_back(v); // Size 2
    EXPECT_EQ(v->get_capacity(v), 8); 

    // Pop to 1 element (1 < 8/4 is 1 < 2 -> True)
    v->pop_back(v); 
    EXPECT_EQ(v->get_size(v), 1);
    EXPECT_EQ(v->get_capacity(v), 4); // Halved from 8
}

TEST_F(VectorTest, Clear) {
    v->push_back(v, 10);
    v->push_back(v, 20);
    int old_cap = v->get_capacity(v);
    
    v->clear(v);
    EXPECT_EQ(v->get_size(v), 0);
    EXPECT_EQ(v->get_capacity(v), old_cap); // Capacity remains
}

TEST_F(VectorTest, FileIO) {
    v->push_back(v, 777);
    v->push_back(v, 888);
    
    const char* filename = "test_dump.txt";
    ASSERT_EQ(dump_vector_to_file(v, filename), 0);

    Vector* v2 = create_vector_from_file(filename);
    ASSERT_TRUE(v2 != nullptr);
    
    EXPECT_EQ(v2->get_size(v2), 2);
    EXPECT_EQ(v2->get_capacity(v2), v->get_capacity(v)); // Restored capacity
    EXPECT_EQ(v2->data[0], 777);
    EXPECT_EQ(v2->data[1], 888);

    v2->destroy(v2);
    remove(filename);
}
