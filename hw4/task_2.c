#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill_arr(int size, int arr[size]) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % 10) + 1;
    }
}

void count_freq(int size, int arr[size], int freq[10]) {
    for (int i = 0; i < 10; i++) freq[i] = 0;
    for (int i = 0; i < size; i++) {
        freq[arr[i] - 1]++;
    }
}

int main() {
    srand(time(NULL));

    int arr[1000];
    int freq[10] = {0};

    fill_arr(1000, arr);
    count_freq(1000, arr, freq);

    int val[10];
    for (int i = 0; i < 10; i++) val[i] = i + 1;

    for (int i = 0; i < 9; i++) {
        int max = i;
        for (int j = i + 1; j < 10; j++) {
            if (freq[j] > freq[max]) max = j;
        }
        if (max != i) {
            int tmpf = freq[i]; freq[i] = freq[max]; freq[max] = tmpf;
            int tmpv = val[i];  val[i]  = val[max];  val[max]  = tmpv;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d: %d\n", val[i], freq[i]);
    }

    return 0;
}
