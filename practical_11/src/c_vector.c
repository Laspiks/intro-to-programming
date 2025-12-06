#include "c_vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Vector* vector_create(size_t capacity, size_t itemsize) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if (!v) return NULL;

    if (capacity == 0) capacity = 2; 

    v->data = malloc(capacity * itemsize);
    if (!v->data) {
        free(v);
        return NULL;
    }

    v->size = 0;
    v->capacity = capacity;
    v->item_size = itemsize;

    return v;
}

void vector_destroy(Vector *v) {
    if (!v) return;
    if (v->data) free(v->data);
    free(v);
}

int vector_push_back(Vector *v, ValueType item) {
    if (!v) return -1;

    if (v->size == v->capacity) {
        size_t new_cap = v->capacity * 2;
        if (new_cap == 0) new_cap = 2;

        void* new_data = realloc(v->data, new_cap * v->item_size);
        if (!new_data) return -1;

        v->data = new_data;
        v->capacity = new_cap;
    }

    void* target = (char*)v->data + (v->size * v->item_size);
    memcpy(target, item, v->item_size);
    
    v->size++;
    return 0;
}

void vector_pop_back(Vector *v, ValueType out_item) {
    if (!v || v->size == 0) return;

    v->size--;

    if (out_item != NULL) {
        void* source = (char*)v->data + (v->size * v->item_size);
        memcpy(out_item, source, v->item_size);
    }

    if (v->size > 0 && v->size == (v->capacity / 4)) {
        size_t new_cap = v->capacity / 2;
        if (new_cap < 2) new_cap = 2;

        void* new_data = realloc(v->data, new_cap * v->item_size);
        if (new_data) {
            v->data = new_data;
            v->capacity = new_cap;
        }
    }
}

void vector_get_element(Vector *v, size_t index, ValueType out_item) {
    if (!v || index >= v->size || !out_item) return;

    void* source = (char*)v->data + (index * v->item_size);
    memcpy(out_item, source, v->item_size);
}

size_t vector_get_item_size(const Vector *v) {
    if (v) {
        return v->item_size;
    } else {
        return 0;
    }
}

size_t vector_get_size(const Vector *v) {
    if (v) {
        return v->size;
    } else {
        return 0;
    }
}

size_t vector_get_capacity(const Vector *v) {
    if (v) {
        return v->capacity;
    } else {
        return 0;
    }
}