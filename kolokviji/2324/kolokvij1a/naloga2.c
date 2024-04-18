
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
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

//=============================================================================

// po potrebi dopolnite ...

bool primerjajNiza(char* niz1, char* niz2){
    if(strlen(niz1) != strlen(niz2)){
        return false;
    }
    for(int i = 0; i < strlen(niz1); i++){
        if(niz1[i] != niz2[i]){
            return false;
        }
    }
    return true; // true ce sta enaka vsebina
}

void racionaliziraj(char** nizi) {
    
    for(int i = 0; nizi[i] != NULL; i++){
        for(int j = i; nizi[j] != NULL; j++){
            if(primerjajNiza(nizi[i], nizi[j])){
                nizi[j] = nizi[i];
            }
        }
    }
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <racionaliziraj> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin 
    // (gcc naloga2.c).
    return 0;
}

#endif
