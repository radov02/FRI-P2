#include <stdio.h>

int conversion(int F);

int main(){

    for(int i = 0; i <= 300; i += 20){
        printf("%3d F \t%3d C\n", i, conversion(i));
    }

    return 0;
}

int conversion(int fahr){
    return 5 * (fahr - 32) / 9;
}