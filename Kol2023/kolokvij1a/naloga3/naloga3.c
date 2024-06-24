
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// po potrebi dopolnite ...

int stNacinov = 0;

int izpisi(int stevilo, int m){

    if(stevilo == 0){
        stNacinov++;
        return 1;
    }

    int nacinov = 0;
    for(int b = m; b <= stevilo; b++){
        for(int a = 1; a < b; a++){
            if(stevilo - a*b >= 0){
                nacinov += izpisi(stevilo - a*b, m);
            }
        }
    }

    return nacinov;
}

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", izpisi(n, m));

    // printf("%d\n", stNacinov);

    return 0;
}
