CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99

# Source files
SRC = src/array_utils.c
DEMO = demo/demo.c
TESTS = tests/tests.c

# Targets
all: demo tests

demo: $(DEMO) $(SRC)
	$(CC) $(CFLAGS) $(DEMO) $(SRC) -o demo/demo

tests: $(TESTS) $(SRC)
	$(CC) $(CFLAGS) $(TESTS) $(SRC) -o tests/tests

clean:
	rm -f demo/demo tests/tests
