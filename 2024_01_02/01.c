#include <stdio.h>

void print(int x) {
        printf("%dx%d의 다이아몬드 모양\n", x, x);
        for (int i = 0; i < x; i++) {
            int tr = (x / 2 - i);
            if (tr < 0) {
                tr = -tr;
            } else {
                tr = tr;
            }
            for (int j = 0; j < tr; j++) {
                printf(" ");
            }
            for (int k = 0; k < 2 * (x / 2 - tr) + 1; k++) {
                printf("*");
            }
            printf("\n");
        }
    }


int main(void) {
    int input=9;
    print(input);
    return 0;
}
