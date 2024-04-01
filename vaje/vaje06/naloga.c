
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "naloga.h"

int steviloZnakov(char* niz, char znak) {
    
    char* trenutniZnak = niz;
    int stevec = 0;

    while(*trenutniZnak != '\0'){

        if(*trenutniZnak == znak){
            stevec++;
        }

        trenutniZnak++; // se poveča za sizeof(char)
    }
    
    return stevec;
}

char* kopirajDoZnaka(char* niz, char znak) {
    
    char* novNiz = (char*) malloc(sizeof(char));
    char* zapisiZnak = novNiz;

    while(*niz != '\0' || *niz != znak){
        *zapisiZnak = *niz;
        zapisiZnak++;
        niz++;
    }
    
    return novNiz;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
    

    
    return NULL;
}

#ifndef test

int main() {

    char* beseda = "sevedsssasemtukaj";
    char ch = 's';
    char* program = "program";

    // printf("%d\n", steviloZnakov(beseda, ch));
    printf("%p\n", kopirajDoZnaka(program, 'o'));



    return 0;
}

#endif
