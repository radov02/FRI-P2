
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga3.c
./a.out

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

01: primer iz besedila
02..05: vsi elementi tabele so med seboj enaki
06..10: splo"sni primeri

Testne datoteke:

test*.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
test*.dat: testni podatki
test*.out: pri"cakovani izhod testnega programa
test*.res: dejanski izhod testnega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "naloga3.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================


Vozlisce* drevo(int n, int* podatki){

    printf(": %d\n", ((int)pow(2, n-1)-1)); fflush(stdout);

    if(((int)pow(2, n-1)-1) == 0){
        return NULL;
    }

    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = podatki[0];
    printf("podatek: %d\n", novo->podatek); fflush(stdout);

    int* levaPodtabela = malloc(((int)pow(2, n-1)-1) * sizeof(int));
    int j = 0;
    for(int i = 1; i < ((int)pow(2, n-1)-1); i++){
        levaPodtabela[j++] = podatki[i];
    }
    int* desnaPodtabela = malloc(((int)pow(2, n-1)-1) * sizeof(int));
    int k = 0;
    for(int i = (int)pow(2, n-1); i < (int)pow(2, n); i++){
        levaPodtabela[k++] = podatki[i];
    }
    
    novo->levo = drevo(podatki[1], levaPodtabela);
    novo->desno = drevo(podatki[(int)pow(2, n-1)], desnaPodtabela);

    return novo;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo lastnoro"cno preveriti.
    // V tem primeru program po"zenite preprosto kot
    // gcc naloga3.c
    // ./a.out
    return 0;
}

#endif
