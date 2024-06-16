
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

void izpisiStNacinov(int n, int m){

    printf("n: %d\n", n);

    if(n == 0){
        stNacinov++;
        printf("ret, n=%d\n", n);
        return;
    }
    else if(n < 0){
        return;
    }

    for(int a = 1; a < n; a++){
        for(int b = m; b < n; b++){
            printf("%d\n", n);
            printf("%d %d\n", a, b);
            if(n-a*b >= 0 && a < b){
                izpisiStNacinov(n-a*b, m);
            }
        }
    }
    printf("---\n");
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);

    izpisiStNacinov(n, m);

    return 0;
}
