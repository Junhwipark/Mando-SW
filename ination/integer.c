#include<stdio.h>
int main(void) {
	int a, b, c;
	int value;
	printf("정수3개를 입력하세요:");
	scanf_s("%d%d%d", &a, &b, &c);

	if (a < b) 
		value = a;
	else
		value = b;
		
	if (value < c)
		printf("제일작은 정수는:%d", value);
	else
		printf("제일작은 정수는:%d", c);

	return 0;

	
}