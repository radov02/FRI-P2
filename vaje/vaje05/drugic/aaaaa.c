
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "naloga copy.h"


int vsota(int* zac, int* kon) {
    int vsota = 0;

    for(int* i = zac; i <= kon; i++){
        vsota += *i;
    }
    return vsota;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {

    if(*indeks == -1){
        *indeks = *kazalec - t;
    }
    else{
        *kazalec = t + *indeks;
    }
}

void frekvenceCrk(char* niz, int** frekvence) {
    int* pogostosti = (int*) calloc(('z' - 'a' + 1), sizeof(int));

    for(int i = 0; niz[i] != '\0'; i++){
        if(niz[i] >= 'a' && niz[i] <= 'z'){
            pogostosti[niz[i] - 'a']++;
        }
        else if(niz[i] >= 'A' && niz[i] <= 'Z'){
            pogostosti[niz[i] - 'A']++;
        }
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
