#include<stdio.h>

int get_tax(int income) {
	if (1001 > income)
		income = income * 0.08;
	else if (1000 < income)
		income = income * 0.1;
}
int main(void) {
	int income;
	printf("�ҵ��� �Է��ϼ���:");
	scanf_s("%d", &income);
	printf("�ҵ漼�� %d �Դϴ�.", get_tax(income));
}