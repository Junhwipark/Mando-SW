#include<stdio.h>

int get_tax(int income) {
	if (1001 > income)
		income = income * 0.08;
	else if (1000 < income)
		income = income * 0.1;
}
int main(void) {
	int income;
	printf("소득을 입력하세요:");
	scanf_s("%d", &income);
	printf("소득세는 %d 입니다.", get_tax(income));
}