#ifndef C_VECTOR_H
#define C_VECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/* Create a vector (dynamic int array) with initial size `size`.
 * Returns pointer to allocated memory, or NULL on failure or if size == 0.
 */
int* create_vector(int size);

/* Append value to the end of the array. The function may reallocate the buffer
 * and returns the (possibly new) pointer which must be assigned by the caller.
 * `size` is a pointer to the current number of elements and will be incremented.
 */
int* push_back(int* ptr, int* size, int value);

/* Remove and return the last element. If array is empty or ptr is NULL,
 * the behaviour is defined to return 0 and size remains 0.
 */
int pop_back(int* ptr, int* size);

/* Print elements separated by spaces and a trailing newline. If ptr is NULL
 * or size == 0, prints an empty line.
 */
void print(const int* ptr, int size);

/* Free the allocated vector. Passing NULL is allowed. */
void free_vector(int* ptr);

#ifdef __cplusplus
}
#endif

#endif // C_VECTOR_H
