#include "gtest/gtest.h"
extern "C" {
#include "custom_getline.h"
}
#include <string.h>
#include <string>
#include <stdio.h>

// Helper to create FILE* from const char*
static FILE* make_stream(const char *s) {
    return fmemopen((void*)s, strlen(s), "r");
}

// Test 1: Regular string input
TEST(CustomGetlineTests, RegularString) {
    const char *s = "Hello, world!";
    FILE *f = make_stream(s);

    char *line = NULL;
    size_t len = 0;

    ssize_t nread = getline(&line, &len, f);
    ASSERT_EQ(nread, (ssize_t)strlen(s));
    ASSERT_STREQ(line, s);

    free(line);
    fclose(f);
}

// Test 2: Empty string input
TEST(CustomGetlineTests, EmptyString) {
    const char *s = "";
    FILE *f = make_stream(s);

    char *line = NULL;
    size_t len = 0;

    ssize_t nread = getline(&line, &len, f);
    ASSERT_EQ(nread, -1);     
    ASSERT_EQ(line, nullptr); 

    fclose(f);
}


// Test 3: Reuse existing buffer (smaller then larger)
TEST(CustomGetlineTests, ReuseAndResize) {
    char *line = (char*)malloc(4);
    size_t len = 4;
    strcpy(line, "A");

    // First short read
    const char *s1 = "ab";
    FILE *f1 = make_stream(s1);
    ssize_t n1 = getline(&line, &len, f1);
    ASSERT_EQ(n1, (ssize_t)strlen(s1));
    ASSERT_STREQ(line, s1);
    fclose(f1);

    // Now a longer read requiring realloc
    const char *s2 = "This is a longer test string";
    FILE *f2 = make_stream(s2);
    ssize_t n2 = getline(&line, &len, f2);
    ASSERT_EQ(n2, (ssize_t)strlen(s2));
    ASSERT_STREQ(line, s2);
    fclose(f2);

    free(line);
}

// Test 4: Very long string
TEST(CustomGetlineTests, LongString) {
    std::string s(10000, 'x');
    FILE *f = fmemopen((void*)s.c_str(), s.size(), "r");

    char *line = NULL;
    size_t len = 0;

    ssize_t nread = getline(&line, &len, f);
    ASSERT_EQ(nread, (ssize_t)s.size());
    ASSERT_EQ(strlen(line), s.size());

    free(line);
    fclose(f);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
