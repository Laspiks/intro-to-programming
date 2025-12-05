#include "c_vector.h"
#include <stdlib.h>
#include <stdio.h>


static void vec_push_back(Vector* vec, int value) {
    if (!vec) return;

    if (vec->size == vec->capacity) {
        int new_cap = vec->capacity * 2;
        if (new_cap == 0) new_cap = 2;
        
        int* new_data = (int*)realloc(vec->data, new_cap * sizeof(int));
        if (!new_data) return;
        
        vec->data = new_data;
        vec->capacity = new_cap;
    }

    vec->data[vec->size] = value;
    vec->size++;
}

static void vec_pop_back(Vector* vec) {
    if (!vec || vec->size == 0) return;

    vec->size--;

    if (vec->capacity > 0 && vec->size < (vec->capacity / 4)) {
        int new_cap = vec->capacity / 2;
        if (new_cap < 2) new_cap = 2; 

        int* new_data = (int*)realloc(vec->data, new_cap * sizeof(int));
        if (new_data) {
            vec->data = new_data;
            vec->capacity = new_cap;
        }
    }
}

static int vec_get_size(const Vector* vec) {
    return vec ? vec->size : 0;
}

static int vec_get_capacity(const Vector* vec) {
    return vec ? vec->capacity : 0;
}

static void vec_clear(Vector* vec) {
    if (!vec) return;
    vec->size = 0;
}

static void vec_print(const Vector* vec) {
    if (!vec) return;
    for (int i = 0; i < vec->size; ++i) {
        printf("%d", vec->data[i]);
        if (i < vec->size - 1) printf(" ");
    }
    printf("\n");
}

static void vec_destroy(Vector* vec) {
    if (!vec) return;
    if (vec->data) {
        free(vec->data);
    }
    free(vec);
}

static void bind_methods(Vector* v) {
    v->push_back = vec_push_back;
    v->pop_back = vec_pop_back;
    v->get_size = vec_get_size;
    v->get_capacity = vec_get_capacity;
    v->clear = vec_clear;
    v->print = vec_print;
    v->destroy = vec_destroy;
}

Vector* create_vector(int initial_requests) {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if (!v) return NULL;

    if (initial_requests <= 0) initial_requests = 2;
    v->capacity = initial_requests * 2;
    v->size = 0;
    
    v->data = (int*)malloc(v->capacity * sizeof(int));
    if (!v->data) {
        free(v);
        return NULL;
    }

    bind_methods(v);
    return v;
}


int dump_vector_to_file(const Vector *vector, const char *filename) {
    if (!vector || !filename) return -1;

    FILE* fp = fopen(filename, "w");
    if (!fp) return -1;

    fprintf(fp, "%d %d\n", vector->size, vector->capacity);
    
    for (int i = 0; i < vector->size; i++) {
        fprintf(fp, "%d", vector->data[i]);
        if (i < vector->size - 1) fprintf(fp, " ");
    }
    fprintf(fp, "\n");

    fclose(fp);
    return 0;
}

Vector* create_vector_from_file(const char *filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return NULL;

    int r_size, r_cap;
    if (fscanf(fp, "%d %d", &r_size, &r_cap) != 2) {
        fclose(fp);
        return NULL;
    }

    // Initialize struct
    Vector* v = (Vector*)malloc(sizeof(Vector));
    if (!v) { fclose(fp); return NULL; }

    v->size = r_size;
    v->capacity = r_cap;
    v->data = (int*)malloc(v->capacity * sizeof(int));
    
    if (!v->data) {
        free(v);
        fclose(fp);
        return NULL;
    }

    bind_methods(v);

    for (int i = 0; i < r_size; i++) {
        if (fscanf(fp, "%d", &v->data[i]) != 1) {
            // Read error or malformed file
            v->destroy(v);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return v;
}