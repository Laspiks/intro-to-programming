#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_utils.h"

// Allocates 2D array
int** allocate_2d_array(int size) {
    if (size <= 0) return NULL;
    
    // Allocate array of pointers
    int** arr = malloc(size * sizeof(*arr));
    if (arr == NULL) return NULL;
    
    // Allocate each row
    for (int i = 0; i < size; i++) {
        arr[i] = malloc(size * sizeof(int*));
        if (arr[i] == NULL) {
            // Clean up already allocated memory if allocation fails
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }
    
    return arr;
}

// Fills the 2D array with random integers
void fill_2d_array(int** arr, int size) {
    if (arr == NULL || size <= 0) return;
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++) {
        int* row = arr[i];
        for (int j = 0; j < size; j++) {
            row[j] = rand() % 100;  // Random number between 0 and 99
        }
    }
}

// Prints the 2D array
void print_2d_array(const int** arr, int size) {
    if (arr == NULL || size <= 0) return;
    for (int i = 0; i < size; i++) {
        const int* row = arr[i];
        for (int j = 0; j < size; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
}
// Sorts each row of the 2D array (using bubble sort for simplicity)
void sort_2d_array(int** arr, int size) {
    if (arr == NULL || size <= 0) return;

    for (int i = 0; i < size; i++) {
        int *row = *(arr + i); // use pointer arithmetic to get row
        // bubble sort the row using pointers
        for (int n = size; n > 1; n--) {
            int *p = row;
            int *q = row + 1;
            for (int k = 1; k < n; k++, p++, q++) {
                if (*p > *q) {
                    int tmp = *p;
                    *p = *q;
                    *q = tmp;
                }
            }
        }
    }
}

// Frees the allocated memory for the 2D array
void free_2d_array(int** arr, int size) {
    if (arr == NULL) return;

    int **p = arr;
    if (size > 0) {
        for (int i = 0; i < size; i++) {
            free(p[i]);
        }
    }
    free(arr);
}
/* Duplicate definition removed (identical to the above). */