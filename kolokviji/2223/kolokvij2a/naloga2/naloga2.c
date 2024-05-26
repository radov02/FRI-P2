
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
#include <limits.h>
#include <stdbool.h>

#include "naloga2.h"

// po potrebi dopolnite ...

//rešitev:
Vozlisce* izbrisiVozlisce(Vozlisce* prejsnje, Vozlisce* trenutno, Vozlisce** glava){    // glava je kazalec na kazalec na vozlišče

    if(prejsnje == NULL){
        *glava = trenutno->naslednje;
        free(trenutno);
        return *glava;
    }
    else{
        prejsnje->naslednje = trenutno->naslednje;
        free(trenutno);
        return prejsnje;
    }   
}

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** na, Vozlisce** nb) {
    
    Vozlisce* prejsnjea = NULL;
    Vozlisce* aa = a;

    while(aa != NULL){
        Vozlisce* prejsnjeb = NULL;
        Vozlisce* bb = b;
        bool najdeno = false;

        while(bb != NULL){
            if(bb->podatek == aa->podatek){
                aa = izbrisiVozlisce(prejsnjea, aa, &a);
                bb = izbrisiVozlisce(prejsnjeb, bb, &b);
                najdeno = true;
                break;
            }
            else{
                prejsnjeb = bb;
                bb = bb->naslednje;
            }
        }
        if(!najdeno){
            prejsnjea = aa;
            aa = aa->naslednje;
        }
    }

    *na = a;
    *nb = b;
}

// poizkus:
/* Vozlisce* izbrisiVozlisce(Vozlisce* prejsnje, Vozlisce* naslednje, bool seznama, Vozlisce* aa, Vozlisce* bb, Vozlisce* a, Vozlisce* b){

    if(seznama){
        aa = naslednje;
    }
    else{
        bb = naslednje;
    }

    if(prejsnje == NULL){
        if(seznama){
            a = naslednje;
            bb = b;
        }
        else{
            b = naslednje;
        }
        return NULL;
    }
    else{
        prejsnje->naslednje = naslednje;
        return prejsnje;
    }
}

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** na, Vozlisce** nb) {
    
    Vozlisce* prejsnjea = NULL;
    Vozlisce* prejsnjeb = NULL;
    Vozlisce* aa = a;
    Vozlisce* bb = b;
    bool prejsnjeNastavljenoa = false;

    while(aa != NULL){
        prejsnjeNastavljenoa = false;
        bb = b;

        while(bb != NULL){
            if(bb->podatek == aa->podatek){
                prejsnjea = izbrisiVozlisce(prejsnjea, aa->naslednje, true, aa, bb, a, b);
                prejsnjeb = izbrisiVozlisce(prejsnjeb, bb->naslednje, false, aa, bb, a, b);
                prejsnjeNastavljenoa = true;
                break;
            }
            prejsnjeb = bb;
            bb = bb->naslednje;
        }
        if(!prejsnjeNastavljenoa){
            prejsnjea = aa;
            aa = aa->naslednje;
        }
    }

    *na = a;
    *nb = b;
} */

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo izlociSkupne testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
