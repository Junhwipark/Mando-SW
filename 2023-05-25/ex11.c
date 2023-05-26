#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int People() {
	int a = 1 + rand() % 6;
	int b = 1 + rand() % 6;
	int c = 1 + rand() % 6;
	int p_total = a + b + c;
	printf("컴퓨터의 주사위=(%d,%d,%d)=%d\n", a, b, c, p_total);
	return p_total;
}


int Computer() {
	int a = 1+ rand() % 6;
	int b = 1+ rand() % 6;
	int c = 1+ rand() % 6;
	int c_total = a + b + c; 
	printf("컴퓨터의 주사위=(%d,%d,%d)=%d\n", a, b, c, c_total);
	return c_total;
}

int main() {
	srand(time(NULL));
	int player = People();
	int com = Computer();
	if (player > com)
		printf("사용자 승리");
	else
		printf("컴퓨터 승리");

	return 0;
}