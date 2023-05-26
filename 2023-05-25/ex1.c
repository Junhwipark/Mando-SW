#include<stdio.h>

int even(int n) {
	n = abs(n);
	if (n % 2 == 0)
		n = 1;
	else
		n = 0;
}

int absolute(int n) {
	n = abs(n);
}

int sign(int n) {
	if (n < 0)
		n = -1;
	else if (n > 0)
		n = 1;
	else
		n = 0;
}

int main(void) {
	int n;
	printf("정수를 입력하세요:");
	scanf_s("%d", &n);
	printf("even()의 결과:%d\n",even(n));
	printf("absolute()의 결과:%d\n", absolute(n));
	printf("sign()의 결과:%d\n", sign(n));
}