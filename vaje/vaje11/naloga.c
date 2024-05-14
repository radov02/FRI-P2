
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int vsotaI(Vozlisce* zacetek) {
    Vozlisce* kopija = zacetek;
    int vsota = 0;

    while(kopija != NULL){
        vsota += kopija->podatek;
        kopija = kopija->naslednje;
    }
    
    return vsota;
}

int vsotaR(Vozlisce* zacetek) {
    if(zacetek == NULL){
        return 0;
    }
    if(zacetek->naslednje == NULL){
        return zacetek->podatek;
    }
    
    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element) {
    Vozlisce* novo = malloc(sizeof(Vozlisce));
    novo->podatek = element;
    novo->naslednje = NULL;

    if(zacetek == NULL || zacetek->podatek >= element) {    // ce je seznam prazen ali je že začetni večji od novega
        novo->naslednje = zacetek;
        return novo;
    }

    Vozlisce* kopija = zacetek;
    while(kopija->naslednje != NULL && kopija->naslednje->podatek < element) {
        kopija = kopija->naslednje;
    }
    novo->naslednje = kopija->naslednje;
    kopija->naslednje = novo;
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element) {

    if(zacetek == NULL || element <= zacetek->podatek){
        Vozlisce* novo = malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->naslednje = zacetek;
        return novo;
    }

    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);
    return zacetek;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje (po "zelji)

    return 0;
}

#endif
