/*F(n) = F(n-1) + F(n-2) (n �� 2)*/

#include<stdio.h>
int main(void) {
	int x;
	int y=0, z=1, f=0;

	printf(" �Է��� ���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &x);

	for (int i = 0; i <= x; i++) {

		printf("%d", y);
		y = z + f;
		y = z;
		z = f;

	}
	return 0;
}