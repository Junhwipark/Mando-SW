#include<stdio.h>
#include<stdlib.h>

int a;

int menu() {
	int n;
	printf("***********welcome to Express ATM***********\n");
	printf("<1> �ܾ�\n");
	printf("<2> �Ա�\n");
	printf("<3> ���\n");
	printf("<4> ����\n");
	printf("�޴��� �����Ͻÿ�:");
	scanf_s("%d", &n);
	return n;
}

int balance() {
	printf("%d�� �Դϴ�.\n", a);
}


int Deposit() {
	int b=0;
	printf("�Աݱݾ��� �Է��ϼ���:");
	scanf_s("%d", &b);
	a = a + b;
	printf("�ܰ�� %d ���Դϴ�.\n", a);
}

int Withdrawal() {
	int c=0;
	printf("�Աݱݾ��� �Է��ϼ���:");
	scanf_s("%d", &c);

	a = a - c;

	if (0>a) 
		printf("�ܰ� �ִ� ���� �����մϴ�.\n");
	else 
		printf("�ܰ�� %d ���Դϴ�.\n", a);
	
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
			printf("�����մϴ�.");
			return 0;

		default:
			printf("�߸��ȼ����Դϴ�.");
			break;
		}
	}
}