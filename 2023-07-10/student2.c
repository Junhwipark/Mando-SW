#include<stdio.h>

struct student {
	int num;
	char name[10];
	double grade;

};

int main() {
	struct student s;

	printf("학번을 입력하세요");
	scanf("%d", &s.num);

	printf("이름을 입력하세요");
	scanf("%s", s.name);

	printf("학점을 입력하세요");
	scanf("%lf", &s.grade);


	printf("%d\n", s.num);
	printf("%s\n", s.name);
	printf("%.2f\n", s.grade);


	return 0;

}