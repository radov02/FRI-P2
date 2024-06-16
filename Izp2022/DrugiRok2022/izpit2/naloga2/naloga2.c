
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test04: celoten seznam tvori cikel (acikli"cni del je prazen)
test05..test10: splo"sni primeri

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define MAX_VOZLISC 1001

int dolzinaCikla(Vozlisce* zacetek) {

    Vozlisce** tabelaZeObiskanih = malloc(MAX_VOZLISC * sizeof(Vozlisce*));
    int indeks = 0;
    Vozlisce* trenutno = zacetek;

    int i = 0, j = 0;
    while(j < MAX_VOZLISC){
        for(i = 0; i < indeks; i++){
            if(tabelaZeObiskanih[i] == trenutno){
                //printf("%p %p\n", tabelaZeObiskanih[i], trenutno);
                goto out;
            }
        }
        tabelaZeObiskanih[indeks++] = trenutno;
        trenutno = trenutno->naslednje;
        j++;
    }
    out:
    return indeks - i;
}


//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo preveriti s svojimi lastnimi
    // testnimi primeri.
    return 0;
}

#endif
