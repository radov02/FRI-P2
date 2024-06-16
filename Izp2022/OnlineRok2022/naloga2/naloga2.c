
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga2.c
./a.out

Samodejno testiranje:

export name=naloga2
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test10: samodejno izdelani, zadnji element prvega seznama < prvi element drugega seznama
test11..test16: samodejno izdelani, splo"sni

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

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

Vozlisce* zlij(Vozlisce* a, Vozlisce* b) {

    Vozlisce* zacetek = malloc(sizeof(Vozlisce));

    if(a->podatek < b->podatek){
        zacetek = a;
        a = a->naslednje;
    }
    else{
        zacetek = b;
        b = b->naslednje;
    }

    while(a != NULL && b != NULL){
            if(a->podatek < b->podatek){    // a je manjsi
                if(a->naslednje == NULL){
                    a->naslednje = b;
                    a = a->naslednje;
                }
                else if(a->naslednje->podatek > b->podatek){   // zamenjamo kazalec
                    Vozlisce* anaslednje = a->naslednje;
                    a->naslednje = b;
                    a = anaslednje;
                }
                else{
                    a = a->naslednje;
                }
            }
            else{   // b je manjsi
                if(b->naslednje == NULL){
                    b->naslednje = a;
                    b = b->naslednje;
                }
                else if(b->naslednje->podatek > a->podatek){   // zamenjamo kazalec
                    Vozlisce* bnaslednje = b->naslednje;
                    b->naslednje = a;
                    b = bnaslednje;
                }
                else{
                    b = b->naslednje;
                }
            }
        // else if(a == NULL){

        // }
        // else if(b == NULL){

        // }
        
    }

    return zacetek;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {
    return 0;
}

#endif
