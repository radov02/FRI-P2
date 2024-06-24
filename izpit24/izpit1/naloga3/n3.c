/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int stevecPotez = 0;

void hanoi(int kolut, int ignoriramo, char zac, char vme, char kon){
    if(kolut <= 1){
        stevecPotez++;
        if(kon == 'B' && stevecPotez > ignoriramo && kolut == 1){
            printf("%d\n", stevecPotez);
        }
        return;
    }

    hanoi(kolut-1, ignoriramo, zac, kon, vme);
    hanoi(0, ignoriramo, zac, vme, kon);    // premik koluta 2 itd.
    hanoi(kolut-1, ignoriramo, vme, zac, kon);  // premik nazaj koluta 1 na kolut 2 itd.
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    hanoi(n, k, 'A', 'B', 'C');     // klic za kolut 4

    return 0;
}   