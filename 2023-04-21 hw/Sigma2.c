#include <stdio.h>

int main(void) {
    
    int sum = 0;

    for ( int i  = 10; i <= 30; i++) {

        
        for (int j = 0; j <= 5; j++) {

            sum += (i + j);

        }

    }

    printf("%d", sum);

    return 0;
}