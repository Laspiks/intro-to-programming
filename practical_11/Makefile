CC = gcc
CXX = g++

CFLAGS = -Wall -Wextra -Iinclude -g
CXXFLAGS = -Wall -Wextra -Iinclude -g

SRC_C = src/c_vector.c
SRC_CPP = tests/c_vector_test.cpp

OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)

all: main tests

main: $(OBJ_C) main.o
	$(CC) $(CFLAGS) -o main main.o $(OBJ_C)
	@echo "Main builded"

tests: $(OBJ_C) $(OBJ_CPP)
	$(CXX) $(CXXFLAGS) -o gtests $(OBJ_CPP) $(OBJ_C) -lgtest_main -lgtest -lpthread
	@echo "Tests builded"
	

# --- compilation rules ------------------------------------
# compile C sources
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# compile C++ sources
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f main gtests **/*.o *.o
	@echo "Cleaned build files"

.PHONY: all clean tests
