#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array_utils.h"

// Allocates 2D array
void** allocate_2d_array(int size) {
   void** arr = (void**)malloc(size * sizeof(void*));
   if (arr == NULL) {
       return NULL;
   }
   for (int i = 0; i < size; i++) {
       arr[i] = (void*)malloc(size * sizeof(int));
       // we need to handle case if malloc returns NULL, but let’s skip it for now
   }
   return arr;
}

// Fills the 2D array with random integers
void fill_2d_array(void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size; j++) {
            row[j] = rand() % 100;  // Random number between 0 and 99
        }
    }
}

// Prints the 2D array
void print_2d_array(const void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size; j++) {
            printf("%d ", row[j]);
        }
        printf("\n");
    }
}

// Sorts each row of the 2D array (using bubble sort for simplicity)
void sort_2d_array(void** arr, int size) {
    for (int i = 0; i < size; i++) {
        int* row = (int*)arr[i];
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (row[k] > row[k + 1]) {
                    int temp = row[k];
                    row[k] = row[k + 1];
                    row[k + 1] = temp;
                }
            }
        }
    }
}

// Frees the allocated memory for the 2D array
void free_2d_array(void** arr, int size) {
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);
}


// this implementation has a bugs - you need to find and fix it using tests
int binary_search_recursive(const int arr[], int left, int right, int target) {
    if (left > right) {
        return -1; // not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binary_search_recursive(arr, left, mid - 1, target);
    } else {
        return binary_search_recursive(arr, mid + 1, right, target);
    }
}

// Wrapper function (simpler interface)
int binary_search(const int arr[], int size, int target) {
    return binary_search_recursive(arr, 0, size-1, target);
}

int fill_2d_array_from_file(void** arr, int size, const char *filename) {
    if (arr == NULL || size <= 0 || filename == NULL) {
        fprintf(stderr, "Invalid arguments\n");
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: cannot open file\n");
        return -1;
    }

    int value;
    for (int i = 0; i < size; i++) {
        int *row = (int *)arr[i];
        if (row == NULL) {
            fprintf(stderr, "Row %d not allocated\n", i);
            fclose(file);
            return -1;
        }

        for (int j = 0; j < size; j++) {
            if (fscanf(file, "%d", &value) == 1) {
                row[j] = value;
            } else {
                // If file ended → fill remaining with 0
                row[j] = 0;
            }
        }
    }

    fclose(file);

    printf("Array filled from file %s:\n", filename);

    return 0;
}
