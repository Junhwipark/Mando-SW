#include<stdio.h>
int main(void) {
	int x , y;

	printf("입력할 정수를 입력하세요:");
	scanf_s("%d", &x);

	
		do {
			y = x % 10;
			printf("%d", y);
			x /= 10;
		} while (x != 0);

		return 0;
}