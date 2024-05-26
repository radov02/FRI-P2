
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

void izbrisi(Vozlisce* predhodnik, Vozlisce* naslednik){
    predhodnik->naslednje = naslednik;
}

void izlociDuplikate(Vozlisce* zacetek) {
    if(zacetek == NULL) return;
    Vozlisce* trenutno = zacetek;

    while(trenutno != NULL){
        Vozlisce* zaPrimerjavo = trenutno->naslednje;
        Vozlisce* prejsnje = trenutno;

        while(zaPrimerjavo != NULL){
            if(trenutno->p == zaPrimerjavo->p){
                izbrisi(prejsnje, zaPrimerjavo->naslednje);
                zaPrimerjavo = prejsnje;
            }
            prejsnje = zaPrimerjavo;
            zaPrimerjavo = zaPrimerjavo->naslednje;
        }
        trenutno = trenutno->naslednje;
    }
}

//=============================================================================

#ifndef test

int main() {
    

    return 0;
}

#endif
