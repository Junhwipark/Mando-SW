#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// 스택 구조체 정의
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화
void initialize(Stack* stack) {
    stack->top = -1;
}

// 스택이 비어있는지 확인
bool isEmpty(Stack* stack) {
    return (stack->top == -1);
}

// 스택이 가득 찼는지 확인
bool isFull(Stack* stack) {
    return (stack->top == MAX_SIZE - 1);
}

// 스택에 데이터 삽입
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
}

// 스택에서 데이터 삭제 및 반환
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;  // 오류 값
    }

    int poppedItem = stack->items[stack->top];
    stack->top--;

    return poppedItem;
}

// 스택의 맨 위 데이터 확인
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("스택이 비어있습니다.\n");
        return -1;  // 오류 값
    }

    return stack->items[stack->top];
}

// 우선순위 반환 함수
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

// 후위 표기법 변환 함수
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
            pop(&stack);  // '(' 제거
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

// 후위 표기법을 이용하여 연산 수행 함수
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
                printf("잘못된 연산자입니다.\n");
                break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char infixExpression[MAX_SIZE];
    char postfixExpression[MAX_SIZE];

    printf("수식을 입력하세요: ");
    fgets(infixExpression, MAX_SIZE, stdin);

    convertToPostfix(infixExpression, postfixExpression);
    printf("후위 표기법: %s\n", postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    printf("결과: %d\n", result);

    return 0;
}
