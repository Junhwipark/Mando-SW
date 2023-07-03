#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    int students[20][6]; 
    int i, j;

    for (i = 0; i < 20; i++) {
        students[i][0] = rand() % 50;       
        students[i][1] = rand() % 30;      
        students[i][2] = rand() % 20;    
        students[i][3] = students[i][0] + students[i][1] + students[i][2];  
    }

    for (i = 0; i < 20; i++) {
        students[i][4] = 1;
        for (j = 0; j < 20; j++) {
            if (students[j][3] > students[i][3]) {
                students[i][4]++;
            }
        }
    }

    printf("�л�\t�߰�\t�⸻\t����\t����\t���\n");
    for (i = 0; i < 20; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, students[i][0], students[i][1], students[i][2], students[i][3], students[i][4]);
    }

    return 0;
}
