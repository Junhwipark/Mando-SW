#include<stdio.h>

struct student {
	int num;
	char name[10];
	double grade;

};

int main() {
	struct student s;

	printf("�й��� �Է��ϼ���");
	scanf("%d", &s.num);

	printf("�̸��� �Է��ϼ���");
	scanf("%s", s.name);

	printf("������ �Է��ϼ���");
	scanf("%lf", &s.grade);


	printf("%d\n", s.num);
	printf("%s\n", s.name);
	printf("%.2f\n", s.grade);


	return 0;

}