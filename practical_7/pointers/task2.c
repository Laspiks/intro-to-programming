#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *left = arr;
    int *right = arr + size - 1;
    while (left < right) {
        int tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;

    printf("Before: ");
    for (int *p = arr; p < arr + size; ++p) printf("%d ", *p);
    printf("\n");

    reverseArray(arr, size);

    printf("After:  ");
    for (int *p = arr; p < arr + size; ++p) printf("%d ", *p);
    printf("\n");

    return 0;
}