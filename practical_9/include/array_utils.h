#ifndef DYNAMIC_2D_ARRAY_INT_H
#define DYNAMIC_2D_ARRAY_INT_H

// Allocates a 2D array, returns NULL in case of errors
void** allocate_2d_array(int size);

// Fills the 2D array with random int numbers
void fill_2d_array(void** arr, int size);

// Prints the 2D array
void print_2d_array(const void** arr, int size);

// Sorts each row of the 2D array
void sort_2d_array(void** arr, int size);

// Frees the allocated memory for the 2D array
void free_2d_array(void** arr, int size);

// Performs binary search on a sorted array
int binary_search(const int arr[], int size, int target);

// Fills the 2D array with numbers from file
int fill_2d_array_from_file(void** arr, int size, const char *filename);

#endif
