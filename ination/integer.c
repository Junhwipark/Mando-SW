#include<stdio.h>
int main(void) {
	int a, b, c;
	int value;
	printf("����3���� �Է��ϼ���:");
	scanf_s("%d%d%d", &a, &b, &c);

	if (a < b) 
		value = a;
	else
		value = b;
		
	if (value < c)
		printf("�������� ������:%d", value);
	else
		printf("�������� ������:%d", c);

	return 0;

	
}