#include<stdio.h>
int main(void) {
	int x, y;
	printf("x좌표와 y좌표를 입력하세요:");
	scanf_s("%d%d", &x, &y);

	if (x > 0 && y > 0)
		printf("제 1사분면입니다.");
	else if (x < 0 && y>0)
		printf("제 2사분면입니다.");
	else if (x < 0 && y < 0)
		printf("제 3사분면입니다.");
	else if (x > 0 && y < 0)
		printf("제 4사분면입니다.");
	else
		printf("원점입니다.");

	return 0;
}