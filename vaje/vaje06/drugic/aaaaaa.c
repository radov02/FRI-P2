
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga copy.h"

int steviloZnakov(char* niz, char znak) {
    int pojavitev = 0;

    for(int i = 0; niz[i] != '\0'; i++){
        if(niz[i] == znak)
            pojavitev++;
    }
    return pojavitev;
}

char* kopirajDoZnaka(char* niz, char znak) {
    int steviloZnakov = 0;
    for(int i = 0; i != '\0'; i++){
        if(niz[i] != znak){
            steviloZnakov++;
        }
    }

    char* tmp = calloc(steviloZnakov, sizeof(char));
    int j = 0;

    for(int i = 0; i != '\0'; i++){
        if(niz[i] != znak){
            tmp[j++] = niz[i];
        }
        else break;
    }

    return tmp;
}

// man
// <string.h>
// strlen
// strncpy
// strchr
// make test P=4-10

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    *stOdsekov = steviloZnakov(niz, locilo) + 1;

    char** tabela = calloc(*stOdsekov, sizeof(char*));
    /* int j = 0;
    tabela[j++] = niz;
    for(int i = 0; j < *stOdsekov && niz[i] != '\0'; i++){
        if(niz[i] == locilo){
            tabela[j++] = niz[i+1];
        }
    } */
    for(int i = 0; i < *stOdsekov; i++){
        tabela[i] = kopirajDoZnaka(niz, locilo);
        niz = niz + strlen(tabela[i]) + 1;
    }

    return tabela;
}

#ifndef test

int main() {

    return 0;
}

#endif
