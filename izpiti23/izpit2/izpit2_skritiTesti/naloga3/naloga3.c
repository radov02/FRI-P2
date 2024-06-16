
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
    Vozlisce* trenutnoVrstica = start;
    int w = 0;
    while(trenutnoVrstica != NULL){
        w++;
        trenutnoVrstica = trenutnoVrstica->desno;
    }

    int vsotai = 0;

    Vozlisce* rezultat = malloc(sizeof(Vozlisce));
    bool zacetnoVozlisce = true;
    Vozlisce* trenutnoVrezultatu = rezultat;
    Vozlisce* trenutnoPremikjoce;
    trenutnoVrstica = start;
    while(trenutnoVrstica != NULL){
        trenutnoPremikjoce = trenutnoVrstica;

        for(int i = 0; i < w-1; i++){
            trenutnoPremikjoce = trenutnoPremikjoce->desno;
        }
        if(w == 0){
            break;
        }

        if(zacetnoVozlisce){
            trenutnoVrezultatu->vsebina = trenutnoPremikjoce->vsebina;
            trenutnoVrezultatu->dol = NULL;
            trenutnoVrezultatu->desno = NULL;
            zacetnoVozlisce = false;
        }
        else{
            Vozlisce* novo = malloc(sizeof(Vozlisce));
            novo->dol = NULL;
            novo->desno = NULL;
            novo->vsebina = trenutnoPremikjoce->vsebina;
            trenutnoVrezultatu->desno = novo;
            trenutnoVrezultatu = novo;
        }
        vsotai += trenutnoVrezultatu->vsebina;

        w--;
        trenutnoVrstica = trenutnoVrstica->dol;
    }

    *vsota = vsotai;

    return rezultat;
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
