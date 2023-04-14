/*3번 사용자로부터 3개 정수를 읽어 들인 후에
if-else문을 사용하여 가장 작은 값을 결정하는 프로그램을 작성하라.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {

	int x, y, z;
	int i;
	

	printf("3개의 정수를 입력하세요.");
	scanf("%d %d %d", & x, &y, &z);


	if (x <= y)
		i = x;

	else{
		i = y;
	}

	if (z <= i)
		i = z;

	printf("제일 작은 정수는%d", i);


	return 0;
}
