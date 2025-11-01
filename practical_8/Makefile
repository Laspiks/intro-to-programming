CC = gcc
COMMON_COMPILE_FLAGS = -Iinclude -Wall -Wextra
CFLAGS = $(COMMON_COMPILE_FLAGS) -std=c99
CXX = g++
CXXFLAGS = $(COMMON_COMPILE_FLAGS) -std=c++17
GTEST_FLAGS = $(shell pkg-config --cflags --libs gtest)

ARRAY_UTILS_OBJ = array_utils.o

.PHONY: all clean

all: demo tests

demo: demo/main.c $(ARRAY_UTILS_OBJ)
	$(CC) $(CFLAGS) demo/main.c $(ARRAY_UTILS_OBJ) -o demo/demo

tests: tests/tests.cpp $(ARRAY_UTILS_OBJ)
	$(CXX) $(CXXFLAGS) tests/tests.cpp $(ARRAY_UTILS_OBJ) $(GTEST_FLAGS) -o tests/tests

$(ARRAY_UTILS_OBJ): src/array_utils.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf demo/demo demo/demo.dSYM tests/tests tests/tests.dSYM $(ARRAY_UTILS_OBJ) 