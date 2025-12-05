#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/c_vector.h"

int main()
{
    srand((unsigned)time(NULL));
    printf("Enter initial vector size: ");
    int n = 0;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Using 5.\n");
        n = 5;
    }

    int* vec = create_vector(n);
    if (!vec) {
        fprintf(stderr, "Allocation failed\n");
        return -1;
    }

    // fill with random ints [-100,100]
    for (int i = 0; i < n; ++i) {
        vec[i] = (rand() % 201) - 100;
    }

    printf("Initial array:\n");
    print(vec, n);

    int size = n;
    int to_add = 5; // append 5 more values
    printf("Appending %d more random values...\n", to_add);
    for (int i = 0; i < to_add; ++i) {
        int val = (rand() % 201) - 100;
        int* new_vec = push_back(vec, &size, val);
        if (!new_vec) {
            fprintf(stderr, "Reallocation failed during push_back\n");
            free_vector(vec);
            return 1;
        }
        vec = new_vec;
    }

    printf("After appends (size=%d):\n", size);
    print(vec, size);

    // pop a couple elements
    printf("Popping last two elements:\n");
    for (int i = 0; i < 2; ++i) {
        int v = pop_back(vec, &size);
        printf("popped: %d\n", v);
    }
    printf("After pops (size=%d):\n", size);
    print(vec, size);

    free_vector(vec);
    return 0;
}
