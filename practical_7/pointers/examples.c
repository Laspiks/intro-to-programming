#include <stdio.h>

void fillArrayWithOne(int arr[], int size);
void printArray(int* arr, int size);

void fill2DArrayWithOne(int n, int arr[n][n]);
void print2DArray(int** arr, int n);
void print2DArrayVLA(int n, int arr[n][n]);

int main() {
    const int N = 5;

    // example #1
    int arr[N];
    fillArrayWithOne(arr, N);
    printf("Example #1 - 1D array:\n");
    printArray(arr, N);

    int arr2D[N][N] = {0};
    fill2DArrayWithOne(N, arr2D);
    // Cast them to `int**` for function compatibility
    int* arr_ptrs[N];
    for (int i = 0; i < N; i++) {
        *(arr_ptrs + i) = *(arr2D + i);
    }

    printf("Example #2 - 2D array:\n");
    print2DArray(arr_ptrs, N);
    printf("Example #2 - 2D variadic-length array:\n");
    print2DArrayVLA(N, arr2D);

    return 0;
}

void fillArrayWithOne(int arr[], int size) {
   for (int i = 0; i < size; i++) {
       *(arr + i) = 1; // the same as arr[i] = 1;
   }
}

void printArray(int* arr, int size) {
   for (int i = 0; i < size; i++) {
       printf("%d ", *(arr + i)); // the same as arr[i]
   }
   printf("\n");
}

void fill2DArrayWithOne(int n, int arr[n][n]){
    for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
              *(*(arr + i) + j) = 1; // the same as arr[i][j] = 1;
         }
    }
}

void print2DArray(int** arr, int n) {
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
           printf("%d ", *(*(arr + i) + j));
       }
       printf("\n");
   }
}

void print2DArrayVLA(int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}
