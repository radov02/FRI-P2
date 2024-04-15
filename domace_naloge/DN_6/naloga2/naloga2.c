
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

//int (*p)[N] = TABELA;   // p je pointer na int array N elementov, inicializiran na prvi array v TABELA - TABELA[0]
// int (*p)[N] je pointer na int array N elementov
// int *p[N] je array N pointerjev na int

/*  int *p = TABELA;     p je pointer na prvi ELEMENT tabele 
    int (*p)[N] = TABELA;    p je pointer na array N integerjev
    ko povečamo prvi p, se premakne na naslednji element v TABELA;
    ko povečamo drugi p, se premakne na naslednji array N elementov v TABELA (poveča se za N * sizeof(int) ... velikost vrstice)
*/

int** ap2pp(int(*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
    
    int **rezultat = malloc(ciljnoStVrstic * sizeof(int*)); // int*!!!
    int stElementovVhodneTabele = izvornoStVrstic * N;
    int indeks = 0; // v prvotni tabeli
    int stElementovVrsticeIzhodneTabele = stElementovVhodneTabele / ciljnoStVrstic + 1;

    for(int i = 0; i < ciljnoStVrstic; i++){
        rezultat[i] = calloc(stElementovVrsticeIzhodneTabele, sizeof(int));        // *(rezultat + i)

        for(int j = 0; j < stElementovVrsticeIzhodneTabele - 1; j++){
            if(indeks >= N){
                kazalec++;
                indeks = 0;
            }

            rezultat[i][j] = (*kazalec)[indeks++];  // vrednost na kazalcu (*kazalec) je naslov
        }
    }

    return rezultat;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
    // pp2ap je ime funkcije
    // (int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic) so parametri funkcije
    // int (*...)[N] je tip funkcije - vrača kazalec na int tabelo z N elementi
    int stElementov = 0;
    for(int i = 0; i < izvornoStVrstic; i++){
        int j = 0;
        while(kazalec[i][j] != 0){
            stElementov++;
            j++;
        }
    }

    *ciljnoStVrstic = (int)((double)stElementov / N + 0.9); // namesto ceil (zaradi prevajanja)
    
    int (*rezultat)[N] = malloc(*ciljnoStVrstic * sizeof(*rezultat));

    int k = -1, l = N+1;
    for(int i = 0; i < izvornoStVrstic; i++){
        int j = 0;
        
        while(kazalec[i][j] != 0){
            
            if(l >= N){
                k++;
                l = 0;
            }
            rezultat[k][l] = kazalec[i][j];

            l++;
            j++;
        }
    }

    return rezultat;   // vrni naslov na prvo vrstico
}

#ifndef test

int main() {

    return 0;
}

#endif
