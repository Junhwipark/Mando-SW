#include<stdio.h>
int main(void) {
	int a;
	printf("약수를 출력할 수를 입력하세요:");
	scanf_s("%d", &a);

	for (int i = 1; i <= a; i++) {
		if (a % i == 0) {
			printf("%d ", i);
		}
	}
	return 0;

}