#ifndef VECTOR_H
#define VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

struct Vector;

typedef struct Vector {
    int* data;      
    int size;       
    int capacity;   

    void (*push_back)(struct Vector* vector, int value);
    void (*pop_back)(struct Vector* vector);
    int (*get_size)(const struct Vector* vector);
    int (*get_capacity)(const struct Vector* vector);
    void (*clear)(struct Vector* vector);
    void (*print)(const struct Vector* vector);
    void (*destroy)(struct Vector* vector);
} Vector;

/* * Create a vector with initial capacity based on `initial_capacity`.
 * Allocates 2 * initial_capacity. Size starts at 0.
 */
Vector* create_vector(int initial_capacity);

/* Task 2: File I/O */
Vector* create_vector_from_file(const char *filename);
int dump_vector_to_file(const Vector *vector, const char *filename);

#ifdef __cplusplus
}
#endif

#endif // VECTOR_H