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
	printf("������ �Է��ϼ���:");
	scanf_s("%d", &n);
	printf("even()�� ���:%d\n",even(n));
	printf("absolute()�� ���:%d\n", absolute(n));
	printf("sign()�� ���:%d\n", sign(n));
}