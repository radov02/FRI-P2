
/*
Ro"cno poganjanje testnih programov (npr. test01.c):

gcc -Dtest test01.c naloga1.c
./a.out

Samodejno testiranje:

export name=naloga1
make test

Testni primeri:

test01: primer iz besedila
test02..test08: ro"cno izdelani kratki testi
test09..test11: samodejno izdelani, tip Exxx_Exxx_Exxx_...
test12..test14: samodejno izdelani, vsakemu E-ju sledi "stevilo iz [100, 999]
test15..test17: samodejno izdelani, splo"sni

.c: testni program (prebere testne podatke, pokli"ce va"so funkcijo in izpi"se rezultat)
.dat: testni podatki
.out: pri"cakovani izhod
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "naloga1.h"

#define MAX_STRING_LEN 100000

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.

//============================================================================

int sestEj(char* niz) {

    int vsota = 0;

    for(int i = 0; i < MAX_STRING_LEN; i++){
        if(niz[i] == '\0'){
            break;
        }

        if(niz[i] == 'E'){
            int j = i;
            bool niOK = false;
            int stevilo = 0;

            while(niz[j] != '_' && niz[j] != '\0'){
                if(j == i && (niz[j+1] < '1' || niz[j+1] > '9')){
                    // število se ne prične z ok števko
                    niOK = true;
                }
                if(j > i && (niz[j] < '0' || niz[j] > '9')){
                    break;
                }
                if(j > i && !niOK){
                    stevilo = stevilo * 10;
                    stevilo += (niz[j] - '0');
                    if(stevilo > 999){
                        break;
                    }
                }
                if(j > i && niz[j] == 'E'){
                    j++;
                    break;
                }
                j++;
            }
            if(niz[j] == '_' && stevilo >= 100 && stevilo <= 999){
                // printf("stevilo: %d\n", stevilo);
                vsota += stevilo;
            }
            i = j-1;
        }
    }
  
    return vsota;
}

//============================================================================

// Vrstici z #ifndef in #endif pustite pri miru!

#ifndef test

int main() {

    return 0;
}

#endif
