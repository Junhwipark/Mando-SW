#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char queue[MAX_SIZE][256];
int front = -1;
int rear = -1;

void initializeQueue() {
    front = -1;
    rear = -1;
}

int isEmpty() {
    return front == -1 && rear == -1;
}

void enqueue(char data[256]) {
    if (rear == MAX_SIZE - 1) {
        printf("큐가 가득 찼습니다. 더 이상 데이터를 추가할 수 없습니다.\n");
        return;
    }

    if (isEmpty())
        front++;

    rear++;
    strcpy(queue[rear], data);
    printf("Enqueued: %s\n", data);
}

void dequeue() {
    if (isEmpty()) {
        printf("큐가 비어 있습니다. 삭제할 데이터가 없습니다.\n");
        return;
    }

    printf("Dequeued: %s\n", queue[front]);

    if (front == rear) {
        initializeQueue();
    } else {
        front++;
    }
}

void peek() {
    if (isEmpty()) {
        printf("큐가 비어 있습니다. Peek할 데이터가 없습니다.\n");
        return;
    }

    printf("Peeked: %s\n", queue[front]); 
}

void printSize() {
    printf("큐의 크기: %d\n", rear - front + 1); 
}

void clearQueue() {
    initializeQueue();
    printf("큐가 초기화되었습니다.\n");
}

int main(void) {
    initializeQueue();

    while (1) {
        int menu;
        printf("1. 큐 초기화 2. 비어 있는지 확인 3. 큐에 추가 4. 큐에서 삭제 5. Peek 6. 큐 크기 7. 큐 비우기 8. 종료\n");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                initializeQueue();
                printf("큐가 초기화되었습니다.\n");
                break;

            case 2:
                if (isEmpty())
                    printf("큐가 비어 있습니다.\n");
                else
                    printf("큐가 비어 있지 않습니다.\n");
                break;

            case 3:
                char data[256];
                printf("데이터 입력: ");
                scanf("%255s", data); 
                enqueue(data);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                peek();
                break;

            case 6:
                printSize();
                break;

            case 7:
                clearQueue();
                break;

            case 8:
                exit(0);

            default:
                printf("올바르지 않은 숫자입니다. 다시 입력하세요.\n");
        }
    }

    return 0;
}
