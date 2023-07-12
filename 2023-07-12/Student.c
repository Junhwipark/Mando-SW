#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 20

struct Student {
    int mid;         // �߰� ���� ����
    int final;       // �⸻ ���� ����
    int assignment;  // ���� ����
    int total;       // ����
    int rank;        // ����
};

typedef struct Student Student;

// ����
void Grades(Student students[]) {
    int i;

    for (i = 0; i < NUM_STUDENTS; i++) {
        students[i].mid = rand() % 40;
        students[i].final = rand() % 30;
        students[i].assignment = rand() % 30;
        students[i].total = 0;
        students[i].rank = 1;
    }
}

// ���� ���
void Total(Student students[]) {
    int i;

    for (i = 0; i < NUM_STUDENTS; i++) {
        students[i].total = students[i].mid + students[i].final + students[i].assignment;
    }
}

// ���� ���
void Rank(Student students[]) {
    int i, j;

    for (i = 0; i < NUM_STUDENTS; i++) {
        for (j = 0; j < NUM_STUDENTS; j++) {
            if (students[i].total < students[j].total) {
                students[i].rank++;
            }
        }
    }
}

// �л����� ������ ���� �����ϴ� �Լ�
void sortStudents(Student students[]) {
    int i, j;
    Student temp;

    for (i = 0; i < NUM_STUDENTS - 1; i++) {
        for (j = 0; j < NUM_STUDENTS - 1 - i; j++) {
            if (students[j].total < students[j + 1].total) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// �л� ���� ��� �Լ�
void printInfo(Student students[]) {
    int i;

    printf("�л� ���� ����:\n");
    printf("=============================\n");
    printf("   �й�   | �߰� | �⸻ | ���� |  ����  |  ����\n");
    printf("----------------------------------------\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("  �л�%d  |  %d  |  %d  |  %d  |  %d  |  %d\n",
            i + 1, students[i].mid, students[i].final,
            students[i].assignment, students[i].total, students[i].rank);
    }
    printf("=============================\n");
}

int main() {
    Student students[NUM_STUDENTS];

    srand(time(NULL));

    // ���� �ʱ�ȭ
    Grades(students);

    // ���� ���
    Total(students);

    // ���� ���
    Rank(students);

    //����
    sortStudents(students);

    //���
    printInfo(students);

    return 0;
}