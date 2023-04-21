/* 2와 100사이에 있는 모든 소수(prime number)를
찾는 프로그램을 작성하라.*/
#include <stdio.h>

int main(void) {
	int j, i;

	for (i = 2; i <= 100; i++) {

		for (j = 2; j < i; j++) {

			if (i % j == 0)

				break;
		}
		if (i == j)

			printf("%d ", i);
	}
	return 0;
}
