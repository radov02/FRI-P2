
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
 * -- 02, 03, 04: en sam vhodni niz;
 * -- 05, 06, 07: vsi vhodni nizi so enako dolgi;
 * -- 01, 08, 09, 10: splo"sni primeri.
 *
 * Javni testni primeri (po na"cinu priprave):
 * -- 01: primer iz besedila;
 * -- 01, 02, 05: ro"cno ustvarjeni;
 * -- ostali: samodejno generirani.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

//=============================================================================

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {

    int najdaljsi = 0;
    for(int i = 0; i < stVhodnih; i++){
        int dolzina = strlen(nizi[i]);
        if(dolzina > najdaljsi){
            najdaljsi = dolzina;
        }
    }
    *stIzhodnih = najdaljsi;

    char** tabela = calloc(*stIzhodnih, sizeof(char*));

    for(int i = 0; i < *stIzhodnih; i++){ // 7x
        
        char* niztmp = calloc(stVhodnih, sizeof(char)); // za dodajanje črk
        int niztmpindex = 0;
        for(int j = 0; j < stVhodnih; j++){ // čez vse besede
            if(strlen(nizi[j]) <= i){
                continue;
            }
            niztmp[niztmpindex++] = nizi[j][i];
        }

        strncpy(niztmp, niztmp, niztmpindex);
        tabela[i] = niztmp;
    }
    
    /* for(int i = 0; i < *stIzhodnih; i++){
        for(int j = 0; j < stVhodnih; j++){
            printf("%c", tabela[i][j]);
        }
        printf("\n");
    }  */

    return tabela;
}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo poStolpcih testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga2.c).

    return 0;
}

#endif
