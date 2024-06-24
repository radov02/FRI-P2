
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

int stNacinov(int n, int m){

    if(n == 0){
        return 1;
    }

    int nacinov = 0;
    for(int b = m; b <= n; b++){
        for(int a = 1; a < b; a++){
            if(n - a*b >= 0){
                nacinov += stNacinov(n - a*b, m);
            }
        }
    }
    return nacinov;
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", stNacinov(n, m));

    return 0;
}
