#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_arr(int arr_size, int arr[arr_size][arr_size]){

    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < arr_size; j++){
            arr[i][j] = rand() % 100;
        }
    }
}

void show_arr(int arr_size, int arr[arr_size][arr_size]){
    
    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < arr_size; j++){
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}


void rotate_arr(int arr_size, int arr[arr_size][arr_size], int rotated_arr[arr_size][arr_size]){
    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < arr_size; j++){
            rotated_arr[j][arr_size - 1 - i] = arr[i][j];
        }
    }
}



int main()
{
    srand(time(NULL));

    const int N = 4;
    int arr[N][N];
    int rotated_arr[N][N];

    // printf("Enter size of 2D array: ");
    // scanf(" %d", &arr_size);
    printf("2D Array elements:\n");
    fill_arr(N, arr);
    show_arr(N, arr);

    rotate_arr(N, arr, rotated_arr);    

    printf("\n2D Array elements after rotation (90° clockwise):\n");
    
    show_arr(N, rotated_arr);

    return 0;
}
