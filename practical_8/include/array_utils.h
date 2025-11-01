#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

// Allocates a 2D array, returns NULL in case of errors
int** allocate_2d_array(int size);

// Fills the 2D array with random int numbers
void fill_2d_array(int** arr, int size);

// Prints the 2D array
void print_2d_array(const int** arr, int size);

// Sorts each row of the 2D array
void sort_2d_array(int** arr, int size);

// Frees the allocated memory for the 2D array
void free_2d_array(int** arr, int size);

#endif
