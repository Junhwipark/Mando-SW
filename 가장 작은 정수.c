/*3�� ����ڷκ��� 3�� ������ �о� ���� �Ŀ�
if-else���� ����Ͽ� ���� ���� ���� �����ϴ� ���α׷��� �ۼ��϶�.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	int x, y, z;
	int i;
	i = 0;

	printf("3���� ������ �Է��ϼ���.");
	scanf("%d %d %d", & x, &y, &z);

	if (x < y)
	    i = x;
		else if(x > y)
			i = y;

	if (z < i)
		i = z;

	printf("���� ���� ������%d", i);


	return 0;
}