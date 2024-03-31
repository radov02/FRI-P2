
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include <stdio.h>
#include <stdlib.h>

#include "naloga1.h"

int* poisci(int* t, int* dolzina, int** konec) {

    int* element = t;
    int dol = 0;

    while(*element != 0){
        element++;
        dol++;
    }

    *konec = (element-1);

    element = t;

    while(*element != 0){
        element--;
        dol++;
    }

    *dolzina = dol-1;

    //printf("dolzina: %p, *konec: %p, *element: %p\n", dolzina, *konec, *(element+1));

    return (element+1);
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)
    return 0;
}

#endif
