#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int arr[], size_t n) {
    srand(time(NULL));
    
    for (size_t i = 0; i < n; ++i) {
        arr[i] = rand() % 100;
    }
}

void print_array(const int arr[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", arr[i]);
    }
    putchar('\n');
}

void bubble_sort(int arr[], size_t n) {
    if (n < 2) return;
    for (size_t i = 0; i < n - 1; ++i) {
        int swapped = 0;
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int binary_search_loop(const int arr[], size_t n, int target) {
    size_t left = 0;
    size_t right = (n == 0) ? 0 : n - 1;
    while (left <= right && n > 0) {
        size_t mid = left + (right - left) / 2;
        if (arr[mid] == target) return (int)mid;
        if (arr[mid] < target) {
            left = mid + 1;
            if (left > right) break;
        } else {
            if (mid == 0) break;
            right = mid - 1;
        }
    }
    return -1;
}
