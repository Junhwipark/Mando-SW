#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Array(int array[5][5]) {
    int max = 25;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int random_index = rand() % max;

            int row = i;
            int col = j;

            while (array[row][col] != 0) {
                if (++col >= 5) {
                    col = 0;
                    if (++row >= 5) {
                        row = 0;
                    }
                }
            }

            array[row][col] = random_index;

            if (--max == 0) {
                return;
            }
        }
    }
}

int main() {
    int array[5][5];

    srand(time(NULL));

    Array(array);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
