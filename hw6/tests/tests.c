#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "array_utils.h"

static int arrays_equal(const int a[], const int b[], size_t n) {
    for (size_t i = 0; i < n; ++i) if (a[i] != b[i]) return 0;
    return 1;
}

int main(void) {
    printf("Running unit tests for bubble_sort and binary_search_loop...\n");

    /* Test bubble_sort */
    int a1[] = {5,3,8,1,4};
    int expected1[] = {1,3,4,5,8};
    bubble_sort(a1, 5);
    assert(arrays_equal(a1, expected1, 5));

    /* Test binary_search_loop on sorted array */
    int sorted[] = {1,3,4,5,8};
    int idx;

    idx = binary_search_loop(sorted, 5, 1);
    assert(idx == 0);

    idx = binary_search_loop(sorted, 5, 5);
    assert(idx == 3);

    idx = binary_search_loop(sorted, 5, 8);
    assert(idx == 4);

    idx = binary_search_loop(sorted, 5, 7);
    assert(idx == -1);

    printf("All tests passed!\n");
    return 0;
}
