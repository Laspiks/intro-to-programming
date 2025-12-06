#include <stdio.h>
#include <stdlib.h>
#include "c_vector.h"

int main() {
    printf("=== Vector Test ===\n");

    /* --- ТЕСТ 1: Вектор целых чисел (int) --- */
    printf("\n[Integer Test]\n");
    Vector* v_int = vector_create(4, sizeof(int));
    
    // Push
    for (int i = 0; i < 10; ++i) {
        int val = i * 10;
        vector_push_back(v_int, &val); // Передаем адрес!
        printf("Pushed: %d | Size: %zu, Cap: %zu\n", val, vector_get_size(v_int), vector_get_capacity(v_int));
    }

    printf("Contents: ");
    for (size_t i = 0; i < vector_get_size(v_int); ++i) {
        int val;
        vector_get_element(v_int, i, &val);
        printf("%d ", val);
    }
    printf("\n");

    printf("Popping elements\n");
    while (vector_get_size(v_int) > 0) {
        int popped_val;
        vector_pop_back(v_int, &popped_val);
        
        size_t cap = vector_get_capacity(v_int);
        size_t size = vector_get_size(v_int);
        if (size == cap / 4 || size == 0) {
            printf("Pop: %d | Size: %zu, Cap: %zu\n", popped_val, size, cap);
        }
    }
    vector_destroy(v_int);


    printf("\n[Double Test]\n");
    Vector* v_dbl = vector_create(2, sizeof(double));
    
    double d1 = 1.1, d2 = 2.2, d3 = 3.3;
    vector_push_back(v_dbl, &d1);
    vector_push_back(v_dbl, &d2);
    vector_push_back(v_dbl, &d3);

    for (size_t i = 0; i < vector_get_size(v_dbl); ++i) {
        double val;
        vector_get_element(v_dbl, i, &val);
        printf("v[%zu] = %.2f\n", i, val);
    }

    vector_destroy(v_dbl);

    return 0;
}