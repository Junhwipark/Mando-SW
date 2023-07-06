//배열 5 x 5 메인에다 만들고
//랜덤 인덱스 에다 0부터 24까지 넣는 함수인데
//while 돌릴때마다 카운트변수 올리고 중복되면 
// 정수안넣고 카운트만 올리는
//함수임

/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int funtion();

int main() {

	srand((unsigned)time(NULL));

	int a[5][5] = {
				{ 10, 20, 30, 40, 50 },
				{ 10, 20, 30, 40, 50 },
				{ 10, 20, 30, 40, 50 },
				{ 10, 20, 30, 40, 50 } ,
				{ 10, 20, 30, 40, 50 } };

	int count=0;
	int i;
	int b;

	funtion(i, b, a, count);

}

void funtion(int x, int y,int z[4][4],int u) {

	while (1) {

		x = rand() % 5;
		y = rand() % 5;
		z[x][y] = rand() % 24;

		if (z[x][y]==z[x][y])
			continue;

		else if (u == 25)
			break;
		else
			u++;
	}


};*/
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int array[5][5]) {
    int count = 0; 
    int numbers[25];

    for (int i = 0; i < 25; i++) {
        numbers[i] = i;  
    }

    srand(time(NULL));  

    while (count < 25) {
        int random_index = rand() % 25;  

        int row = random_index / 5;
        int col = random_index % 5;

        if (array[row][col] == 0) {  
            array[row][col] = numbers[count];
            printf("%d", count);
            count++;
        }
    }
}

int main() {
    int array[5][5];

    fillArray(array);

   
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int array[5][5]) {
    int remaining = 25;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int random_index = rand() % remaining;

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

            if (--remaining == 0) {
                return;
            }
        }
    }
}

int main() {
    int array[5][5];

    srand(time(NULL));

    fillArray(array);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/
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

