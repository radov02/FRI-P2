#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina){
    if(mesto == 0){
        Vozlisce* tmp = malloc(sizeof(Vozlisce));
        Vozlisce* zgornje = malloc(sizeof(Vozlisce));
        tmp = start;
        while(tmp != NULL){
            Vozlisce* novo = malloc(sizeof(Vozlisce));
            novo->vsebina = vsebina;
            vsebina++;
            if(tmp == start){
                start = novo;
            }
            else{
                zgornje->dol = novo;
            }
            novo->desno = tmp;
            tmp = tmp->dol;
            zgornje = novo;
        }
        zgornje->dol = NULL;
    }
    else{
        Vozlisce* zgornje = malloc(sizeof(Vozlisce));
        zgornje = start;
        for(int i = 0; i < mesto-1; i++){
            zgornje = zgornje->desno;
        }

        Vozlisce* tmp = malloc(sizeof(Vozlisce));
        Vozlisce* prejsnje = malloc(sizeof(Vozlisce));
        prejsnje = NULL;
        tmp = zgornje;
        while(tmp != NULL){
            Vozlisce* novo = malloc(sizeof(Vozlisce));
            novo->vsebina = vsebina;
            vsebina++;
            novo->desno = tmp->desno;
            tmp->desno = novo;
            if(prejsnje != NULL){
                prejsnje->dol = novo;
            }
            prejsnje = novo;
            tmp = tmp->dol;
        }
    }
    return start;
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