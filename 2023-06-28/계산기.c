#include <stdio.h>

int main() {
    char op, oq;
    int a, b, result;

    printf("===���� ���α׷�===\n");
    printf("������ �Է��ϼ���. (��: 3 + 3)\n");
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
            printf("\n�߸� �Է��ϼ̽��ϴ�.");
            while (getchar() != '\n');
            continue;
        }

        printf("\n��� ���: %d", result);

        printf("\n���� ������ �Է��ϼ���.\n");
        scanf(" %c %d", &op, &b);

        while (getchar() != '\n');

        if (op == '+' || op == '-' || op == '*' || op == '/')
            a = result;
        else if (op == 'q')
            break;
        else {
            printf("\n�߸� �Է��ϼ̽��ϴ�.");
            while (getchar() != '\n');
        }
    }

    return 0;
}