#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// ���� ����ü ����
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// ���� �ʱ�ȭ
void initialize(Stack* stack) {
    stack->top = -1;
}

// ������ ����ִ��� Ȯ��
bool isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// ������ ���� á���� Ȯ��
bool isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// ���ÿ� ������ ����
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("������ ���� á���ϴ�.\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

// ���ÿ��� ������ ���� �� ��ȯ
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("������ ����ֽ��ϴ�.\n");
        return -1;  // ���� ��
    }

    int poppedItem = stack->items[stack->top];
    stack->top--;

    return poppedItem;
}

// ������ �� �� ������ Ȯ��
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("������ ����ֽ��ϴ�.\n");
        return -1;  // ���� ��
    }

    return stack->items[stack->top];
}

// �켱���� ��ȯ �Լ�
int getPriority(char operator) {
    if (operator == '*' || operator == '/') {
        return 2;
    }
    else if (operator == '+' || operator == '-') {
        return 1;
    }
    else {
        return 0;
    }
}

// ���� ǥ��� ��ȯ �Լ�
void convertToPostfix(char* infixExpression, char* postfixExpression) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    int j = 0;
    char symbol;

    while ((symbol = infixExpression[i++]) != '\0') {
        if (isdigit(symbol)) {
            postfixExpression[j++] = symbol;
        }
        else if (symbol == '(') {
            push(&stack, symbol);
        }
        else if (symbol == ')') {
            while (peek(&stack) != '(') {
                postfixExpression[j++] = pop(&stack);
            }
            pop(&stack);  // '(' ����
        }
        else {
            while (!isEmpty(&stack) && getPriority(symbol) <= getPriority(peek(&stack))) {
                postfixExpression[j++] = pop(&stack);
            }
            push(&stack, symbol);
        }
    }

    while (!isEmpty(&stack)) {
        postfixExpression[j++] = pop(&stack);
    }

    postfixExpression[j] = '\0';
}

// ���� ǥ����� �̿��Ͽ� ���� ���� �Լ�
int evaluatePostfix(char* postfixExpression) {
    Stack stack;
    initialize(&stack);

    int i = 0;
    int operand1, operand2;
    char symbol;

    while ((symbol = postfixExpression[i++]) != '\0') {
        if (isdigit(symbol)) {
            push(&stack, symbol - '0');
        }
        else {
            operand2 = pop(&stack);
            operand1 = pop(&stack);

            switch (symbol) {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            default:
                printf("�߸��� �������Դϴ�.\n");
                break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("������ �Է��ϼ���: ");
    fgets(infixExpression, MAX_SIZE, stdin);

    convertToPostfix(infixExpression, postfixExpression);
    printf("���� ǥ���: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("���: %d\n", result);

    return 0;
}
