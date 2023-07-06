#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

int main() {
    int A[SIZE][SIZE];
    int filled = 0;

    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = -1;
        }
    }

    
    srand(time(0));

    while (filled < SIZE * SIZE) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;

        
        if (A[row][col] == -1) {
            A[row][col] = filled;
            filled++;
        }
    }

   
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%2d ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
