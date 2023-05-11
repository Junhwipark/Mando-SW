#include<stdio.h>

void printmeun()
{
	printf("1. in를 cm로 변환하는것:\n");
	printf("2. cm를 in로 변환하는것:\n");
	printf("3. km를 ya로 변환하는것:\n");
	printf("4. ya를 km로 변환하는것:\n");
}


double in_to_cm(double i_c)
{
	return i_c * 2.54;
}

double cm_to_in(double c_i)
{
	return c_i *0.393701;
}

double km_to_ya(double k_y)
{
	return k_y *1,093.6133;
}

double ya_to_km(double y_k)
{
	return y_k *0.000914;
}


int main(void) {

	double a;
	int choice;

	printmeun();
	printf("번호를 입력하세요:");
	scanf_s("%d", &choice);



	switch (choice)
	{

	case 1:
		printf("in: ");
		scanf_s("%lf", &a);
		printf("%lf", in_to_cm(a));
		break;
	case 2:
		printf("cm: ");
		scanf_s("%lf", &a);
		printf("%lf", cm_to_in(a));
		break;
	case 3:
		printf("km: ");
		scanf_s("%lf", &a);
		printf("%lf", km_to_ya(a));
		break;
	case 4:
		printf("ya: ");
		scanf_s("%lf", &a);
		printf("%lf", ya_to_km(a));
		break;
	}

	return 0;

}