#include <stdio.h>
#include <stdlib.h>
#include "array_utils.h"


int main(void) {
    const int N = 10;
    int arr[N];

    generate_random_array(arr, N);
    printf("Generated array:\n");
    print_array(arr, N);

    printf("\nEnter integer value to search for: ");
    
    int value;
    if (scanf("%d", &value) != 1) {
        printf("Invalid input\n");
        return -1;
    }

    bubble_sort(arr, N); // O(n^2)
    printf("\nSorted array:\n");
    print_array(arr, N);

    int idx = binary_search_loop(arr, N, value); // O(log n)
    if (idx >= 0) {
        printf("Index: %d\n", idx);
    } else {
        printf("Value %d not found\n", value);
    }

    // char str[] = "Hello, World!";
    // int key = 3;
    
    // printf("Original string: %s\n", str);
    // shift_string(str, key);
    // printf("Shifted string (key=%d): %s\n", key, str);
    
    return 0;
}
