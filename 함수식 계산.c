/*다음과 같이 정의되는 함수의 함수값을 계산하여보자.
사용자로부터 x값을 받아서 함수값을 계산하여 화면에 출력한다. x는 실수이다*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int x;
	printf("정수를 입력하세요:");
	scanf("%d", &x);

	if (x <= 0) {
		printf('%d',x * x - 9 * x + 2);
	}

	else if (x > 0) {
		printf('%d',7 * x + 2);
	}
	

	return 0;
}