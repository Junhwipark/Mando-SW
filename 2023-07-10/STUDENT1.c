#include<stdio.h>
#include<stdlib.h>

struct student {
	int num;
	char name[10];
	double grade;

};

int main() {
	struct student s;

	s.num = 2023001;
	strcpy(s.name, "ȫ�浿");
	s.grade = 4.3;


	printf("�й�:%d\n", s.num);
	printf("�̸�:%s\n", s.name);
	printf("����:%.2f\n", s.grade);


	return 0;

}