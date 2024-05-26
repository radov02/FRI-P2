
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga2
 * make test
 *
 * Testni primeri:
 * 02--06: a = 1, b = n
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void izpisi(char** razbitja, int razbitjaIndex, char* niz, int n, int a, int b){

    
    for(int i = 0; i < n; i++){
        
    }

}

int main() {

    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    char* niz = malloc(n*sizeof(char));
    for(int i = 0; i < n; i++){
        scanf("%s", &niz[i]);
    }



    free(niz);

    return 0;
}
