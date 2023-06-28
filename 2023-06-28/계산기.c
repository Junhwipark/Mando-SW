#include <stdio.h>

int main() {
    char op, oq;
    int a, b, result;

    printf("===계산기 프로그램===\n");
    printf("계산식을 입력하세요. (예: 3 + 3)\n");
    scanf("%d %c %d", &a, &op, &b);

    while (1) {
        if (op == '+')
            result = a + b;
        else if (op == '-')
            result = a - b;
        else if (op == '*')
            result = a * b;
        else if (op == '/')
            result = a / b;
        else {
            printf("\n잘못 입력하셨습니다.");
            while (getchar() != '\n');
            continue;
        }

        printf("\n계산 결과: %d", result);

        printf("\n다음 계산식을 입력하세요.\n");
        scanf(" %c %d", &op, &b);

        while (getchar() != '\n');

        if (op == '+' || op == '-' || op == '*' || op == '/')
            a = result;
        else if (op == 'q')
            break;
        else {
            printf("\n잘못 입력하셨습니다.");
            while (getchar() != '\n');
        }
    }

    return 0;
}