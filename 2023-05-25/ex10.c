#include<stdio.h>
#include<time.h>
int a;
int randint(int a) {
	for (int i = 0; i < 10; i++) {
		a = 10 + rand() % 79;
			printf("%d ", a);
	}

}
int main(void) {
	printf("%d", randint(a));
}