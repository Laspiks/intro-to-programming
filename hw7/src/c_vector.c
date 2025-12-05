#include "../include/c_vector.h"
#include <stdlib.h>
#include <stdio.h>

int* create_vector(int n)
{
	if (n <= 0) n = 1;
	int *v = (int*)calloc((size_t)n, sizeof(int));
	return v;
}

int* push_back(int *vec, int *size, int val)
{
	if (size == NULL) return NULL;

	int new_size = (*size) + 1;
	int *tmp = (int*)realloc(vec, (size_t)new_size * sizeof(int));
	if (tmp == NULL) {
		return NULL;
	}
	tmp[new_size - 1] = val;
	*size = new_size;
	return tmp;
}

int pop_back(int *vec, int *size)
{
	if (size == NULL || *size <= 0) {
		return 0;
	}
	int val = vec[(*size) - 1];
	(*size)--;
	
	return val;
}

void print(const int *vec, int n)
{
	if (vec == NULL || n <= 0) {
		printf("\n");
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (i) printf(" ");
		printf("%d", vec[i]);
	}
	printf("\n");
}

void free_vector(int *vec)
{
	free(vec);
}
