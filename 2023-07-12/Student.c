#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 20

struct Student {
    int mid;         // 중간 시험 점수
    int final;       // 기말 시험 점수
    int assignment;  // 과제 점수
    int total;       // 총점
    int rank;        // 석차
};

typedef struct Student Student;

// 성적
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

// 총점 계산
void Total(Student students[]) {
    int i;

    for (i = 0; i < NUM_STUDENTS; i++) {
        students[i].total = students[i].mid + students[i].final + students[i].assignment;
    }
}

// 석차 계산
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

// 학생들을 총점에 따라 정렬하는 함수
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

// 학생 정보 출력 함수
void printInfo(Student students[]) {
    int i;

    printf("학생 성적 정보:\n");
    printf("=============================\n");
    printf("   학번   | 중간 | 기말 | 과제 |  총점  |  석차\n");
    printf("----------------------------------------\n");
    for (i = 0; i < NUM_STUDENTS; i++) {
        printf("  학생%d  |  %d  |  %d  |  %d  |  %d  |  %d\n",
            i + 1, students[i].mid, students[i].final,
            students[i].assignment, students[i].total, students[i].rank);
    }
    printf("=============================\n");
}

int main() {
    Student students[NUM_STUDENTS];

    srand(time(NULL));

    // 성적 초기화
    Grades(students);

    // 총점 계산
    Total(students);

    // 석차 계산
    Rank(students);

    //정렬
    sortStudents(students);

    //출력
    printInfo(students);

    return 0;
}