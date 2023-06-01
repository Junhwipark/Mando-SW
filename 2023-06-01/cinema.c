#include <stdio.h>
#define SIZE 20

int main(void) {

    char ans1;
    int ans2, i;
    int ans3;
    int seats[SIZE] = { 0 };

    while (1)
    {
        printf("�¼��� �����Ͻðڽ��ϱ�? (y �Ǵ� n): ");
        scanf_s(" %c", &ans1);

        if (ans1 == 'n')
            break;

        printf("-----------------------------\n");
        printf(" 1  2  3  4  5  6  7  8  9 10\n");
        printf("11 12 13 14 15 16 17 18 19 20\n");
        printf("-----------------------------\n");

        for (i = 0; i < SIZE; i++)
            printf("%d ", seats[i]);
        printf("\n");

        printf("�� ���Դϱ�? ");
        scanf_s("%d", &ans3);

        if (ans3 > 1)
        {
            for (int e = 0; e < ans3; e++) {
                printf("�� ��° �¼��� �����Ͻðڽ��ϱ�? ");
                scanf_s("%d", &ans2);

                if (ans2 < 1 || ans2 > SIZE) {
                    printf("��ȿ���� ���� �¼� ��ȣ�Դϴ�.\n");
                    continue;
                }

                if (seats[ans2 - 1] == 0) {
                    seats[ans2 - 1] = 1;
                    printf("����Ǿ����ϴ�.\n");
                }
                else {
                    printf("�̹� ����� �¼��Դϴ�.\n");
                    e--;
                }
            }
        }
        else if (ans3 == 1) {
            printf("�� ��° �¼��� �����Ͻðڽ��ϱ�? ");
            scanf_s("%d", &ans2);

            if (ans2 < 1 || ans2 > SIZE) {
                printf("��ȿ���� ���� �¼� ��ȣ�Դϴ�.\n");
                continue;
            }

            if (seats[ans2 - 1] == 0) {
                seats[ans2 - 1] = 1;
                printf("����Ǿ����ϴ�.\n");
            }
            else {
                printf("�̹� ����� �¼��Դϴ�.\n");
            }
        }
    }

    return 0;
}

