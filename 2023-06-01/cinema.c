#include <stdio.h>
#define SIZE 20

int main(void) {

    char ans1;
    int ans2, i;
    int ans3;
    int seats[SIZE] = { 0 };

    while (1)
    {
        printf("좌석을 예약하시겠습니까? (y 또는 n): ");
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

        printf("몇 명입니까? ");
        scanf_s("%d", &ans3);

        if (ans3 > 1)
        {
            for (int e = 0; e < ans3; e++) {
                printf("몇 번째 좌석을 예약하시겠습니까? ");
                scanf_s("%d", &ans2);

                if (ans2 < 1 || ans2 > SIZE) {
                    printf("유효하지 않은 좌석 번호입니다.\n");
                    continue;
                }

                if (seats[ans2 - 1] == 0) {
                    seats[ans2 - 1] = 1;
                    printf("예약되었습니다.\n");
                }
                else {
                    printf("이미 예약된 좌석입니다.\n");
                    e--;
                }
            }
        }
        else if (ans3 == 1) {
            printf("몇 번째 좌석을 예약하시겠습니까? ");
            scanf_s("%d", &ans2);

            if (ans2 < 1 || ans2 > SIZE) {
                printf("유효하지 않은 좌석 번호입니다.\n");
                continue;
            }

            if (seats[ans2 - 1] == 0) {
                seats[ans2 - 1] = 1;
                printf("예약되었습니다.\n");
            }
            else {
                printf("이미 예약된 좌석입니다.\n");
            }
        }
    }

    return 0;
}

