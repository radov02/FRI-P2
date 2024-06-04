#include <stdio.h>
#include <stdlib.h>
#include "naloga.h"

int vsotaI(Vozlisce* zacetek){
    int vsota = 0;
    if(zacetek == NULL) return vsota;
    Vozlisce* temp = zacetek;
    while(temp->naslednje != NULL){
        vsota += temp->podatek;
        temp = temp->naslednje;
    }
    vsota += temp->podatek;
    return vsota;
}

int vsotaR(Vozlisce* zacetek){
    if(zacetek == NULL){
        return 0;
    }
    if(zacetek->naslednje == NULL){
        return zacetek->podatek;
    }

    return zacetek->podatek + vsotaR(zacetek->naslednje);
}

Vozlisce* vstaviUrejenoI(Vozlisce* zacetek, int element){

    Vozlisce* novo = malloc(sizeof(Vozlisce*));
    novo->podatek = element;

    if(zacetek == NULL){
        zacetek = novo;
        zacetek->naslednje = NULL;
        return zacetek;
    }
    if(zacetek->naslednje == NULL || zacetek->podatek >= element){
        if(zacetek->podatek < element){
            novo->naslednje = NULL;
            zacetek->naslednje = novo;
        }
        else{
            novo->naslednje = zacetek;
            zacetek = novo;
        }
        return zacetek;
    }

    Vozlisce* temp = zacetek;
    while(temp->naslednje != NULL && novo->podatek > temp->naslednje->podatek){
        temp = temp->naslednje;
    }
    if(temp->naslednje == NULL){
        novo->naslednje = NULL;
        temp->naslednje = novo;
    }
    else{
        novo->naslednje = temp->naslednje;
        temp->naslednje = novo;
    }
    return zacetek;
}

Vozlisce* vstaviUrejenoR(Vozlisce* zacetek, int element){

    Vozlisce* novo = malloc(sizeof(Vozlisce*));
    novo->podatek = element;

    if(zacetek == NULL){
        novo->naslednje = NULL;
        return novo;
    }
    if(element < zacetek->podatek){
        novo->naslednje = zacetek;
        return novo;
    }

    zacetek->naslednje = vstaviUrejenoR(zacetek->naslednje, element);

    return zacetek;
}

#ifndef test
int main(){



    return 0;
}
#endif