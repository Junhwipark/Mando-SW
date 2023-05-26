#include<stdio.h>

int check_alpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
		printf("%c는 알파벳입니다.\n", c);
	
	else 
		printf("%c는 알파벳이 아닙니다.\n", c);
	

}
int main(void) {
	char c;
	printf("문자를 입력하세요:");
	scanf_s("%c", &c);

	printf("%c",check_alpha(c));

	return 0;
}
