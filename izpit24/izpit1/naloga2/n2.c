
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -Dtest testXY.c naloga2.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Javni testni primeri:
 *
 * 02..03: n <= 2000, k = 1, D >= 2
 * 04..05: n <= 2000, D >= k + 1
 * 01, 06..08: n <= 2000
 * 09..10: n <= 100000
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

//=============================================================================

void obdelaj(Vozlisce* zacetek, int k) {

    int premikajocaVsota = 0;
    Vozlisce* trenutnoM1 = zacetek;
    Vozlisce* prejsnjekto = zacetek;
    for(int i = 0; i < k-1; i++){
        premikajocaVsota += trenutnoM1->podatek;
        trenutnoM1 = trenutnoM1->naslednje;
    }
    premikajocaVsota += trenutnoM1->podatek;

    while(trenutnoM1->naslednje != NULL){
        // printf("pv:%d\n", premikajocaVsota);
        // printf("tnp: %d\n", trenutnoM1->naslednje->podatek);
        if(trenutnoM1->naslednje->podatek == premikajocaVsota){
            trenutnoM1->naslednje = trenutnoM1->naslednje->naslednje;
        }
        else{
            trenutnoM1 = trenutnoM1->naslednje;
            premikajocaVsota -= prejsnjekto->podatek;
            premikajocaVsota += trenutnoM1->podatek;
            prejsnjekto = prejsnjekto->naslednje;
        }
    }

    return;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <obdelaj> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin 
    // (gcc naloga2.c).
    return 0;
}

#endif
