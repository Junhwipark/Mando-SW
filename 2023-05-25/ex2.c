#include<stdio.h>

int check_alpha(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
		printf("%c�� ���ĺ��Դϴ�.\n", c);
	
	else 
		printf("%c�� ���ĺ��� �ƴմϴ�.\n", c);
	

}
int main(void) {
	char c;
	printf("���ڸ� �Է��ϼ���:");
	scanf_s("%c", &c);

	printf("%c",check_alpha(c));

	return 0;
}
