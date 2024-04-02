
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

    /* int dolzinaNiza = strlen(niz);
    char* pZnak = strchr(niz, znak); */
    
    char* kazalec = niz;
    int n = 0;

    while(*kazalec != '\0' && *kazalec != znak && strlen(kazalec) > 0){
        n++;
        kazalec++;
    }

    char* vrni = (char*) malloc((n+1)*sizeof(char));

    strncpy(vrni, niz, n);

    if(n <= strlen(niz)){
        vrni[n] = '\0';
    }
    
    return vrni;
}

// man
// <string.h>
// strlen
// strncpy
// strchr
// make test P=4-10

char** razcleni(char* niz, char locilo, int* stOdsekov) {

    *stOdsekov = steviloZnakov(niz, locilo)+1;
    
    char** tabelaKazalcevNaOdseke = (char**) malloc(*stOdsekov * sizeof(char*));

    for(int i = 0; i < *stOdsekov; i++){
        tabelaKazalcevNaOdseke[i] = kopirajDoZnaka(niz, locilo);
        niz += strlen(tabelaKazalcevNaOdseke[i]) + 1;
    }

    return tabelaKazalcevNaOdseke;
}

#ifndef test

int main() {

    /* char* beseda = "sevedsssasemtukaj";
    char ch = 's';
    char* program = "program";

    // printf("%d\n", steviloZnakov(beseda, ch));
    printf("%p\n", kopirajDoZnaka(program, 'o')); */

    /* char* niz = "prijazen niz z enim samim presledkom med besedami";
    printf("%s\n", kopirajDoZnaka(niz, ' ')); */

    /* char* niz = "";
    printf("%s\n", kopirajDoZnaka(niz, '_')); */

    /* char* niz = "prijazen niz z enim samim presledkom med besedami";
    int stOdsekov = 0;
    char** odseki = razcleni(niz, ' ', &stOdsekov); */

   /*  printf("%d\n",stOdsekov);

    for (int i = 0;  i < stOdsekov;  i++) {
        printf("%d: <%s>\n", i + 1, odseki[i]);
        free(odseki[i]);
    }
    free(odseki); */

    return 0;
}

#endif
