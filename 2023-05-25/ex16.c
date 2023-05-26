#include<stdio.h>
#include<stdlib.h>

int a;

int menu() {
	int n;
	printf("***********welcome to Express ATM***********\n");
	printf("<1> 잔액\n");
	printf("<2> 입금\n");
	printf("<3> 출금\n");
	printf("<4> 종료\n");
	printf("메뉴를 선택하시오:");
	scanf_s("%d", &n);
	return n;
}

int balance() {
	printf("%d원 입니다.\n", a);
}


int Deposit() {
	int b=0;
	printf("입금금액을 입력하세요:");
	scanf_s("%d", &b);
	a = a + b;
	printf("잔고는 %d 원입니다.\n", a);
}

int Withdrawal() {
	int c=0;
	printf("입금금액을 입력하세요:");
	scanf_s("%d", &c);

	a = a - c;

	if (0>a) 
		printf("잔고에 있는 돈이 부족합니다.\n");
	else 
		printf("잔고는 %d 원입니다.\n", a);
	
}
int main(void) {
	while (1)
	{
		switch (menu()) {
		case 1:
			balance();
			break;

		case 2:
			Deposit();
			break;

		case 3:
			Withdrawal();
			break;
		case 4:
			printf("종료합니다.");
			return 0;

		default:
			printf("잘못된선택입니다.");
			break;
		}
	}
}