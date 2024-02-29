#include <stdio.h>

int main(){

    int a = 1;
    int b = 2;
    int sum = 2;

    while(b <= 4000000){
        int tmp = a;
        a = b;
        b += tmp;
        printf("%d\n", b);

        if(b % 2 == 0){
            sum += b;
        }
    }

    printf("%d", sum);

    return 0;
}