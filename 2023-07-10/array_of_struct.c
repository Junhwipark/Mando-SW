#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 3

struct student
{
	int num;
	char name;
	double grade;
};


int main() {

	struct student list[SIZE];
	int i;

	for (i = 0; i < SIZE; i++) {
		printf("학번을 입력하세요");
		scanf("%d", &list[i].num);
		printf("이름을 입력하세요");
		scanf("%s", &list[i].name);
		printf("학점을 입력하세요");
		scanf("%lf", &list[i].grade);

	}

	for (i = 0; i < SIZE; i++)
		printf("이름:%d 학점:%lf", list[i].name, list[i].grade);

	return 0;

}