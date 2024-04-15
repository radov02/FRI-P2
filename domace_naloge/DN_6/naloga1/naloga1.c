
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

/* gcc -D=test test01.c naloga1.c
./a.out */

char* zdruzi(char** nizi, char* locilo) {

    int steviloCrk = 0, steviloBesed = 0;
    char **p = nizi;
    while(*p != NULL){
        steviloCrk += strlen(*p);
        steviloBesed++;
        p++;
    }

    //printf("%d, %ld, %d, %ld\n", steviloCrk, strlen(locilo), steviloBesed, steviloCrk + 1 + strlen(locilo) * (steviloBesed - 1));
    char* novNiz = (char*) malloc((steviloCrk + 1 + strlen(locilo) * (steviloBesed - 1)) * sizeof(char));
    
    int i = 0;
    while(*nizi != NULL){
        //printf("*nizi: %p\n", *nizi);
        while(**nizi != '\0'){
            //printf("**nizi: %c\n", **nizi);
            novNiz[i] = **nizi;
            (*nizi)++;  // NEPRAVILNO: **nizi++; KER SE ŽELIMO PREMAKNITI NAPREJ ZA ČRKO (++ veže močneje)
            i++;
        }

        if(steviloBesed > 1){
            char* loc = locilo;
            while(*loc != '\0'){
                novNiz[i] = *loc;
                loc++;
                i++;
            }
        }
        *nizi++;    // PREMIK NAPREJ NA DRUGO BESEDO (++ veže močneje)
        steviloBesed--;
    }
    novNiz[i] += '\0';

    return novNiz;
}

#ifndef test

int main() {
    // koda za ro"cno testiranje

    return 0;
}

#endif
