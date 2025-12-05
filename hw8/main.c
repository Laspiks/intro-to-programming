#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/c_vector.h"

int main()
{
    srand((unsigned)time(NULL));
    printf("Enter initial vector size request: ");
    int n = 0;
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Using 5.\n");
        n = 5;
    }

    // Create vector. NOTE: Size starts at 0, Capacity starts at n * 2.
    Vector* vec = create_vector(n);
    if (!vec) {
        fprintf(stderr, "Allocation failed\n");
        return -1;
    }

    // Fill with random ints [-100,100]
    // CHANGED: We must use push_back because the vector starts with size 0.
    // Accessing vec->data[i] directly right now is unsafe/incorrect logic 
    // because vec->size is 0.
    for (int i = 0; i < n; ++i) {
        int val = (rand() % 201) - 100;
        vec->push_back(vec, val);
    }

    printf("Initial array (Size: %d, Cap: %d):\n", vec->get_size(vec), vec->get_capacity(vec));
    vec->print(vec);
 
    printf("Appending 5 more random values...\n");
    for (int i = 0; i < 5; ++i) {
        int val = (rand() % 201) - 100;
        vec->push_back(vec, val);
    }

    printf("After appends (Size: %d, Cap: %d):\n", vec->get_size(vec), vec->get_capacity(vec));
    vec->print(vec);

    // Pop a couple elements
    printf("Popping last two elements:\n");
    for (int i = 0; i < 2; ++i) {
        if (vec->get_size(vec) > 0) {
            int v = vec->data[vec->get_size(vec) - 1]; // Peek last
            vec->pop_back(vec);
            printf("popped: %d\n", v);
        }
    }

    printf("After pops (Size: %d, Cap: %d):\n", vec->get_size(vec), vec->get_capacity(vec));
    vec->print(vec);

    // CHANGED: Cleanup using destroy
    vec->destroy(vec);
    return 0;
}