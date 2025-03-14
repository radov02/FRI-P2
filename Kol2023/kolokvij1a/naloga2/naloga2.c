
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
#include <limits.h>

// po potrebi dopolnite ...

//=============================================================================

char** poStolpcih(char** nizi, int stVhodnih, int* stIzhodnih) {
    
    int najdaljsiNiz = 0;
    int* dolzineNizov = malloc(stVhodnih*sizeof(int));
    for(int i = 0; i < stVhodnih; i++){
        int dolzina = strlen(nizi[i]);
        dolzineNizov[i] = dolzina;
        if(dolzina > najdaljsiNiz){
            najdaljsiNiz = dolzina;
        }
    }
    *stIzhodnih = najdaljsiNiz;

    char** vrniTabela = malloc(najdaljsiNiz*sizeof(char*));
    int* indeksiNaIzhodnihNizih = calloc(najdaljsiNiz, sizeof(int));
    for(int i = 0; i < najdaljsiNiz; i++){
        vrniTabela[i] = calloc(stVhodnih, sizeof(char));
    }
    
    int crka = 0;
    while(crka < najdaljsiNiz){
        
        for(int j = 0; j < stVhodnih; j++){ // po besedah
            if(crka < dolzineNizov[j]){
                vrniTabela[crka][indeksiNaIzhodnihNizih[crka]++] = nizi[j][crka];
            }
        }

        crka++;
    }

    return vrniTabela;
}

//=============================================================================

#ifndef test

char* NIZI[] = {
    "Danes",
    "je",
    "kolokvij",
    "pri_P2!",
};

int main() {
    int stIzhodnih = 0;
    char** rezultat = poStolpcih(NIZI, sizeof(NIZI) / sizeof(NIZI[0]), &stIzhodnih);
    printf("%d\n", stIzhodnih);

    for (int i = 0; i < stIzhodnih; i++) {
        printf("%s\n", rezultat[i]);
        free(rezultat[i]);
    }
    free(rezultat);

    return 0;
}

#endif
