
/*
 * Prevajanje in zagon testnega programa testXY.c:
 *
 * gcc -D=test testXY.c naloga3.c
 * ./a.out
 *
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02, 03: h = 1
 * 04, 05, 06: preverjajo samo vsoto
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* diagonala(Vozlisce* start, int* vsota) {

    Vozlisce* novSeznam = malloc(sizeof(Vozlisce));
    Vozlisce* rezultatTrenutno = malloc(sizeof(Vozlisce));

    Vozlisce* tmp = malloc(sizeof(Vozlisce));
    tmp = start;
    int j = 0;
    while(tmp->desno != NULL){  // najdemo prvo vozlisce
        j++;
        tmp = tmp->desno;
    }
    Vozlisce* kopiraj = malloc(sizeof(Vozlisce));
    *vsota += tmp->vsebina;
    kopiraj->vsebina = tmp->vsebina;
    kopiraj->desno = tmp->desno;
    kopiraj->dol = NULL;
    novSeznam = kopiraj;
    rezultatTrenutno = kopiraj;

    if(start->dol != NULL){ // gremo v 2. vrstico
        tmp = start->dol;
    }
    else{
        return novSeznam;
    }
    while(tmp != NULL){
        j--;
        for(int i = 0; i < j; i++){
            tmp = tmp->desno;
        }
        /* Vozlisce* kopija = malloc(sizeof(Vozlisce));
        *vsota += tmp->vsebina;
        kopija->vsebina = tmp->vsebina;
        kopija->desno = NULL;
        kopija->dol = NULL;
        rezultatTrenutno->desno = kopija;
        rezultatTrenutno = kopija; */
    }

    return novSeznam;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <diagonala> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
