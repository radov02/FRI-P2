
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

// po potrebi dopolnite ...

bool zeVidena(int* spremenljivka, int** zeVidene, int indeks){
    // printf("zevidena?\n");fflush(stdout);
    for(int i = 0; i < indeks; i++){
        if(spremenljivka == zeVidene[i]){
            return true;
        }
    }
    return false;
}

void izlociDuplikate(Vozlisce* zacetek) {
    // shranimo kazalce na ze videne spremenljivke
    if(zacetek == NULL) return;
    if(zacetek->naslednje == NULL) return;

    Vozlisce* prejsnje = zacetek;
    int** tabelaKazalcevNaVideneSpr = malloc(1000*sizeof(int*));
    int indeksTabele = 0;
    tabelaKazalcevNaVideneSpr[indeksTabele++] = zacetek->p;
    Vozlisce* trenutno = zacetek->naslednje;

    while(trenutno != NULL){
        if(!zeVidena(trenutno->p, tabelaKazalcevNaVideneSpr, indeksTabele)){
            // printf("nisevidena: %d\n", *trenutno->p);fflush(stdout);
            tabelaKazalcevNaVideneSpr[indeksTabele++] = trenutno->p;
            prejsnje = trenutno;
            trenutno = trenutno->naslednje;
        }
        else{
            // printf("zevidena: %d\n", *trenutno->p);fflush(stdout);
            prejsnje->naslednje = trenutno->naslednje;
            trenutno = trenutno->naslednje;
        }
    }

    return;
}

//=============================================================================

#ifndef test

int main() {
    

    return 0;
}

#endif
