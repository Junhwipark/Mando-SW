#include<stdio.h>
#include<time.h>
#define SIZE 30

int main(void) {

	srand((unsigned)time(NULL));
	int list[SIZE];
	
	for (int i = 0; i < SIZE; i++) {
		list[i] = rand() % 199 - 99;
	}

	int i, j, temp, least;

	for (i = 0; i < SIZE - 1; i++) {

		least = i;
		for (j = i + 1; j < SIZE; j++)
			if (list[j] < list[least])
				least = j;
		temp = list[i];
		list[i] = list[least];
		list[least] = temp;
	}
	for (i = 0; i < SIZE; i++)
		printf(" %d", list[i]);
	printf("\n");

	for (i=SIZE;i>0; i--)
		printf(" %d", list[i-1]);
	printf("\n");
	return 0;
}