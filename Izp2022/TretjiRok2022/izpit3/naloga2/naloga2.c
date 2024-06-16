
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

01: primer iz besedila
02..04: ena sama vrstica
05..06: vsaka neprazna vrstica je naslovna
07..10: splo"sni primeri

Datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
test*.dat: testni podatki
test*.out: pri"cakovani izhod testnega programa
test*.res: dejanski izhod testnega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define MAX_VOZLISC 1000
#define MAX_ZNAKOV_VRSTICA 1000

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================



void vstaviH1(Vozlisce* zacetek) {

    Vozlisce* trenutno = zacetek;
    Vozlisce* prejsnje = malloc(sizeof(Vozlisce));
    prejsnje->niz = "";
    prejsnje->naslednje = zacetek;

    while(trenutno != NULL){
        if(strcmp(trenutno->niz, "") != 0 && strcmp(prejsnje->niz, "") == 0 && (trenutno->naslednje == NULL || strcmp(trenutno->naslednje->niz, "") == 0)){
            // trenutno je naslovna vrstica
            char* tmp = malloc((strlen(trenutno->niz) + 9 + 1)*sizeof(char));
            strcpy(tmp, "<h1>");    // najprej strcpy na že alociran prostor, potem pa strcat
            strcat(tmp, trenutno->niz);
            strcat(tmp, "</h1>\0");
            strcpy(trenutno->niz, tmp);
        }

        prejsnje = trenutno;
        trenutno = trenutno->naslednje;
    }
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {

    return 0;
}

#endif
