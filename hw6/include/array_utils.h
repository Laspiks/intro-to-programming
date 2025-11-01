#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stddef.h>

/* Generate n random integers in range [0,99] and store into arr */
void generate_random_array(int arr[], size_t n);

/* Print n elements of arr */
void print_array(const int arr[], size_t n);

/* Sort arr of length n using bubble sort */
void bubble_sort(int arr[], size_t n);

/* Iterative binary search on sorted arr of length n.
	Returns index of target if found, otherwise -1. */
int binary_search_loop(const int arr[], size_t n, int target);


/* shift all string for the KEY places*/
void shift_string(char *str, int key);

#endif /* ARRAY_UTILS_H */
