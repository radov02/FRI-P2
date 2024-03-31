
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include <stdio.h>

#include "naloga2.h"

void zamenjaj(int** a, int** b) {
    //printf("*a: %p, *b: %p\n", *a, *b);
    int* tmp = *a;
    *a = *b;
    *b = tmp;
    //printf("*a: %p, *b: %p\n", *a, *b);
}

void uredi(int** a, int** b, int** c) {
    
    if(**a > **c){  // a** vrednost na lokaciji kazalca *a
        zamenjaj(a, c);
    }
    if(**a > **b){
        zamenjaj(a, b);
    }
    if(**b > **c){
        zamenjaj(b, c);
    }

}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
