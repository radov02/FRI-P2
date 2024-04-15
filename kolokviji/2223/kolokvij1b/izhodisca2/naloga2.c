
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

// po potrebi dopolnite ...

//=============================================================================

char** naSredino(char** nizi, int ciljnaDolzina) {
    int nizov = 0;
    for(int i = 0; nizi[i] != NULL; i++){
        nizov++;
    }
    
    char** tabela = calloc(nizov+1, sizeof(char*));
    int i = 0;
    for(;i < nizov; i++){
        char* novniz = calloc(ciljnaDolzina + 1, sizeof(char));
        int indeks = 0;
        int dolzinaNiza = strlen(nizi[i]);
        int pik = ciljnaDolzina - dolzinaNiza;
        int desnihPik = pik/2;

        for(int j = 0; j < desnihPik; j++){
            novniz[indeks++] = '.';
        }
        for(int j = 0; j < dolzinaNiza; j++){
            novniz[indeks++] = nizi[i][j];
        }
        for(int j = 0; j < pik - desnihPik; j++){
            novniz[indeks++] = '.';
        }
        novniz[indeks] = '\0';
        tabela[i] = novniz;
    }
    tabela[i] = NULL;

    return tabela;
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
