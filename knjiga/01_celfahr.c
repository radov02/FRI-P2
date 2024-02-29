#include <stdio.h>

int main(){

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 10;

    fahr = lower;
    while(fahr <= upper){
        celsius = 5/9.0 * (fahr - 32);
        printf("%3.0f F\t%6.1f C\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}