#include "array_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_array(int *arr, size_t n) {
    srand((unsigned)time(NULL));
    int *p = arr;
    int *end = arr + n;
    while (p < end) {
        *p++ = rand() % 100;
    }
}

void print_array(const int *arr, size_t n) {
    const int *p = arr;
    const int *end = arr + n;
    while (p < end) {
        printf("%d ", *p++);
    }
    printf("\n");
}

void bubble_sort(int *arr, size_t n) {
    if (n < 2) return;
    for (size_t i = 0; i < n - 1; ++i) {
        int swapped = 0;
        size_t limit = n - 1 - i;
        int *p = arr;
        for (size_t j = 0; j < limit; ++j) {
            int *cur = p + j;
            int *next = cur + 1;
            if (*cur > *next) {
                int tmp = *cur;
                *cur = *next;
                *next = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int binary_search_loop(const int *arr, size_t n, int target) {
    if (n == 0) return -1;
    size_t left = 0;
    size_t right = n - 1;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        int mid_val = *(arr + mid);
        
        if (mid_val == target) return (int)mid;

        if (mid_val < target) {
            left = mid + 1;
            if (left > right) break;
        } else {
            if (mid == 0) break;
            right = mid - 1;
        }
    }
    return -1;
}


void shift_string(char *str, int key) {
    if (!str || !*str) return;
    
    char *end = str;
    size_t len = 0;
    while (*end++) len++;
    
    key = ((key % len) + len) % len;
    if (key == 0) return;

    char *temp = malloc(key * sizeof(*temp));
    if (!temp) return;

    char *src = str + (len - key);        
    char *dst = temp;                     
    for (size_t i = 0; i < (size_t)key; i++) {    
        *dst++ = *src++;                  
    }

    src = str + (len - key - 1);          
    dst = str + (len - 1);                
    while (src >= str) {                  
        *dst-- = *src--;                  
    }

    src = temp;                           
    dst = str;                            
    for (size_t i = 0; i < (size_t)key; i++) {    
        *dst++ = *src++;                      

    }

    free(temp);
}