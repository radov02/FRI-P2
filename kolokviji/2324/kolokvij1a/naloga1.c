
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga1
 * make test
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

int main() {
    
    int n;
    scanf("%d", &n);

    int zacetekDela = 0;
    bool narasca = true;
    long predhodni = -1000000000;
    for(int i = 0; i < n; i++){
        long trenutni = 0;
        scanf("%ld", &trenutni);
        if(trenutni < predhodni && narasca){
            narasca = false;
            printf("%d\n", i - zacetekDela);
            zacetekDela = i-1;
        }
        else if(trenutni > predhodni && !narasca){
            narasca = true;
            printf("%d\n", i - zacetekDela);
            zacetekDela = i-1;
        }
        predhodni = trenutni;
    }
    printf("%d\n", n - zacetekDela);
    
    return 0;
}
