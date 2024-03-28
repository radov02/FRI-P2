
#include <stdio.h>
#include <stdlib.h>

#include "naloga.h"

int vsota(int* zac, int* kon) {
    int vsota = 0;
    for(int i = *zac; i <= *kon; i++){
        vsota += i;
    }
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    // t kaže na začetek tabele
    // indeks kaže na spremenljivko, v kateri bo indeks elementa v tabeli
    // kazalec kazalec kaže na kazalec, ki kaže na element v tabeli
    if(*indeks == -1){
        *indeks = *kazalec - t;
    }
    else{
        *kazalec = t + *indeks;
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    // za sprehajanje čez tabele naredimo nov kazalec, da ohranimo še enega na začetku
    // [] imajo prednost pred *
    int* pogostosti = (int*)calloc(26, sizeof(int));

    int i = 0;
    while(niz[i] != '\0'){
        if(niz[i] >= 'a'){
            int crka = niz[i] - 'a';
            pogostosti[crka]++;
        }
        else{
            pogostosti[niz[i] - 'A']++;
        }
        i++;
    }

    *frekvence = pogostosti;
}

#ifndef test

int main() {
    
    int array[] = {1, 2, 3, 4, 5};
    printf("%d\n", vsota(array, array + 4));

    return 0;
}

#endif
