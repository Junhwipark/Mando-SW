#include<stdio.h>
int main(void) {
	int x , y;

	printf("�Է��� ������ �Է��ϼ���:");
	scanf_s("%d", &x);

	
		do {
			y = x % 10;
			printf("%d", y);
			x /= 10;
		} while (x != 0);

		return 0;
}