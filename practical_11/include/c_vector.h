#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef void* ValueType;

typedef struct Vector {
    void* data;         
    size_t size;        
    size_t capacity;    
    size_t item_size;   
} Vector;

Vector* vector_create(size_t capacity, size_t itemsize);
void vector_destroy(Vector *v);

int vector_push_back(Vector *v, ValueType item);
void vector_pop_back(Vector *v, ValueType item);
void vector_get_element(Vector *v, size_t index, ValueType out_item);

size_t vector_get_item_size(const Vector *v);
size_t vector_get_size(const Vector *v);
size_t vector_get_capacity(const Vector *v);

#endif