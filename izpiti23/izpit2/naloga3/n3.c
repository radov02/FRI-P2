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
    Vozlisce* tmp = start;
    Vozlisce* startCol = start;
    int h = 0;
    while(tmp != NULL){
        h++;
        tmp = tmp->dol;
    }
    int w = 0;
    tmp = start;
    while(tmp != NULL){
        w++;
        if(tmp->desno == NULL){
            break;
        }
        tmp = tmp->desno;
    }

    Vozlisce* rezultatFunkcije = malloc(sizeof(Vozlisce));
    rezultatFunkcije->desno = NULL;
    rezultatFunkcije->dol = NULL;
    rezultatFunkcije->vsebina = tmp->vsebina;
    *vsota += rezultatFunkcije->vsebina;
    Vozlisce* trenutnoVrez = rezultatFunkcije;

    startCol = startCol->dol;
    while(startCol != NULL){
        tmp = startCol;
        for(int i = 0; i < w-2; i++){
            tmp = tmp->desno;
        }
        w--;
        if(w <= 0){
            break;
        }

        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->desno = NULL;
        novo->dol = NULL;
        novo->vsebina = tmp->vsebina;
        *vsota += novo->vsebina;
        trenutnoVrez->desno = novo;
        trenutnoVrez = novo;

        startCol = startCol->dol;
    }

    return rezultatFunkcije;
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
