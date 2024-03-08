/* #include <stdio.h>
#include <math.h>

int main(){
    float num = 1.0;
    float step = 0.1;

    while(fabsf(num) > 0.001){  // NE PREVERJAMO ENAKOSTI, AMPAK BLIŽINO NIČLI
        printf("%f %12.9f\n", num, num);
        num = num - step;
    }

    printf("%f\n", num);
    return 0;
} */

/* #include <stdio.h>
#include <stdbool.h>

int main(){
    float a = 1.0;
    float b = 1.0;

    while((a + b) + b == a + (b + b)){
        printf("%f %f : %f == %f\n", a, b, (a + b) + b, a + (b + b));
        b = b / 2.0;
    }

    printf("%f %f : %.9f != %.9f\n", a, b, (a + b) + b, a + (b + b));

    bool logVrednost = true;
    printf("\n");
    printf("%ld\n", sizeof(bool));
    printf("%ld\n", sizeof(int));
    printf("%ld\n", sizeof(long int));
    printf("%ld\n", sizeof(float));
    printf("%ld\n", sizeof(double));
    printf("%ld\n", sizeof(long double));

    return 0;
} */

/* #include <stdio.h>

int f();

int main(){
    printf("%d\n", f(3));
    printf("%d\n", f(3.14));
    
    return 0;
}

int f(int n){
    printf("[%d]\n", n);
    return 2 * n;
} */

#include <stdio.h>

int main(){

    int n = 5;
    int k = 2;

    for(int i = 0; i < (1 << n); i++){  // (i < 32)
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                printf("B");
            }
            else{
                printf("A");
            }
        }
        printf("\n");
    }

    return 0;
}