/*������ ���� ���ǵǴ� �Լ��� �Լ����� ����Ͽ�����.
����ڷκ��� x���� �޾Ƽ� �Լ����� ����Ͽ� ȭ�鿡 ����Ѵ�. x�� �Ǽ��̴�*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int x;
	printf("������ �Է��ϼ���:");
	scanf("%d", &x);

	if (x <= 0) {
		printf('%d',x * x - 9 * x + 2);
	}

	else if (x > 0) {
		printf('%d',7 * x + 2);
	}
	

	return 0;
}