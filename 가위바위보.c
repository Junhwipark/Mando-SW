/*컴퓨터와 가위,바위,보 게임을 하는 프로그램을 작성하라. 
컴퓨터는 사용자에게 알리지 않고 가위, 바위, 보 중에서 임의로 하나를 선택한다. 
사용자는 프로그램의 입력 안내 메시지에 따라서, 3개 중에서 하나를 선택하게 된다. 
사용자의 선택이 끝나면 컴퓨터는 누가 무엇을 선택하였고 누가 이겼는지, 비겼는지 알려준다.*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) {
	
	srand((unsigned int)time(NULL));

	int x; 
	int y = (rand() % 3 + 1);

	printf("(1:가위 2:바위 3:보) 중에서 하나를 선택하시오: ");
	scanf("%d", &x);

	if (y == 1)
		printf("컴퓨터는 가위를 냈습니다.\n");
	else if (y == 2)                   
		printf("컴퓨터는 바위를 냈습니다.\n");
	else if (y == 3)
		printf("컴퓨터는 보을 냈습니다.\n");

	if (x == y)
		printf("비겼습니다.\n");
	else if ((x == 1 && y == 3) || (x == 2 && y == 1) || (x == 3 && y == 2))
		printf("이겼습니다.\n");
	else if ((x == 1 && y == 2) || (x == 2 && y == 3) || (x == 3 && y == 1))
		printf("졌습니다.\n");

	return 0;


}