#include<stdio.h>

int main(void) {
	int i;
	int sum = 0;

	for (i = 1; i <= 30; i++) {
		sum = (i * i) + 1;
		
	}

	printf("%d", sum);

	return 0;
}