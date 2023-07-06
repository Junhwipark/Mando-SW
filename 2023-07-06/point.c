#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void rand_arry(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void sort_arry(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int merge_arry(int* a, int* b, int* c, int size) {
    int i = 0, j = 0, k = 0;
    while (i < size && j < size) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        }
        else if (a[i] > b[j]) {
            c[k++] = b[j++];
        }
        else {
            c[k++] = a[i++];
            j++;
        }
    }

    while (i < size) {
        c[k++] = a[i++];
    }

    while (j < size) {
        c[k++] = b[j++];
    }

    return k;
}

void print_arry(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(0));
    int a[SIZE], b[SIZE], c[SIZE * 2];

    rand_arry(a, SIZE);
    rand_arry(b, SIZE);

    sort_arry(a, SIZE);
    sort_arry(b, SIZE);

    int newSize = merge_arry(a, b, c, SIZE);

    printf("Array A: ");
    print_arry(a, SIZE);
    printf("Array B: ");
    print_arry(b, SIZE);
    printf("Array C: ");
    print_arry(c, newSize);

    return 0;
}

