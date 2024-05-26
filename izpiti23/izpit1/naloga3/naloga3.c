
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
 * 04, 05, 06: mesto = 0
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

// po potrebi dopolnite ...

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina){

    Vozlisce* startRet = start;
    Vozlisce* trenutno = start;
    Vozlisce* prejsnje = calloc(1, sizeof(Vozlisce*));
    Vozlisce* prvoVvrstici = start;
    int vsebinaVstavi = vsebina;
    bool prvic = true;

    int j = 0;
    while(trenutno != NULL){
        
        while(trenutno != NULL){

            Vozlisce* novo = malloc(sizeof(Vozlisce*));
            novo->vsebina = vsebinaVstavi;

            if(mesto == 0){
                novo->desno = trenutno;
                novo->dol = trenutno->dol;
                if(prejsnje != NULL){
                    prejsnje->dol = novo;
                }
                if(novo->dol == NULL){
                    return startRet;
                }
                if(prvic){
                    startRet = novo;
                }
                trenutno = novo->dol;
                prejsnje = novo;
                vsebinaVstavi++;
                prvic = false;
            }
            else if(j == mesto-1){
                novo->desno = trenutno->desno;
                trenutno->desno = novo;
                vsebinaVstavi++;
                trenutno = trenutno->dol;
            }
            j++;
        }

        if(prvoVvrstici == NULL){
            return startRet;
        }
        prvoVvrstici = prvoVvrstici->dol;
        trenutno = prvoVvrstici;
        j = 0;
    }

    free(prejsnje);
    return startRet;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <vstaviStolpec> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
