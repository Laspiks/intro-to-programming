#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "array_utils.h"

int main(void) {
    int size;

    // Ask user for the size of the NxN array
    printf("Enter the size of the 2D array (N x N): ");
    scanf("%d", &size);

    // Allocate the 2D array
    void** array = allocate_2d_array(size);
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Fill the array with random numbers
    fill_2d_array_from_file(array, size, "./demo/demo.txt");

    // Print the original array
    printf("\nOriginal array:\n");
    print_2d_array((const void**)array, size);

    // Sort the array
    sort_2d_array(array, size);

    // Print the sorted array
    printf("\nSorted array:\n");
    print_2d_array((const void**)array, size);

    // Free the array
    free_2d_array(array, size);

    sleep(1); // <-- keep process alive so leaks can detect memory

    return 0;
}
