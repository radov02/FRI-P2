
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test07: ro"cno izdelani kratki testi
test08..test09: samodejno izdelani, n = 1
test10..test17: samodejno izdelani, n > 1

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "naloga2.h"

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce** tabelaSeznamov(int* t, int d, int n) {

    Vozlisce** tabelaKazalcevNaPrvaVozliscaSeznamov = malloc(n*sizeof(Vozlisce*));
    
    for(int i = 0; i < n; i++){
        Vozlisce* seznam = malloc(sizeof(Vozlisce));
        bool prvo = true;
        Vozlisce* prejsnje = seznam;
        int korak = (int)pow(2, i);
        for(int j = korak-1; j < d; j += korak){
            Vozlisce* novo = malloc(sizeof(Vozlisce));
            novo->vTabelo = &t[j];
            novo->naslednje = NULL;
            if(prvo){
                seznam = novo;
                prvo = false;
            }
            prejsnje->naslednje = novo;
            prejsnje = novo;
        }

        // dodaj seznam
        tabelaKazalcevNaPrvaVozliscaSeznamov[i] = seznam;
    }

    return tabelaKazalcevNaPrvaVozliscaSeznamov;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    // Tole dopolnite, "ce "zelite funkcijo testirati s svojimi lastnimi
    // podatki.
    return 0;
}

#endif
