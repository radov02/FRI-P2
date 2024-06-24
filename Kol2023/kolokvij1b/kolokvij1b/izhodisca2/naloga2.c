
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
 *
 * Javni testni primeri (po te"zavnosti):
 * -- 02, 03: dol"zina vsakega vhodnega niza je enaka ciljnaDolzina;
 * -- 04, 05, 06, 07: dol"zina vsakega vhodnega niza je enaka 1;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 04: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// po potrebi dopolnite ...

//=============================================================================

char** naSredino(char** nizi, int ciljnaDolzina) {

    int i = 0;
    while(nizi[i] != NULL){
        i++;
    }
    
    char** vrniTabela = malloc((i+1)*sizeof(char*));
    for(int j = 0; j < i; j++){
        vrniTabela[j] = malloc(ciljnaDolzina*sizeof(char));
        int nizijlen = strlen(nizi[j]);
        int pik = ciljnaDolzina - nizijlen;

        for(int k = 0; k < pik/2; k++){
            vrniTabela[j][k] = '.';
        }
        for(int k = 0; k < nizijlen; k++){
            vrniTabela[j][k+pik/2] = nizi[j][k];
        }
        for(int k = 0; k < ceil(pik/2.0); k++){     // uporabi double!!
            vrniTabela[j][k+nizijlen+(int)ceil(pik/2)] = '.';
        }
    }
    vrniTabela[i] = NULL;

    return vrniTabela;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo naSredino testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).
    return 0;
}

#endif
