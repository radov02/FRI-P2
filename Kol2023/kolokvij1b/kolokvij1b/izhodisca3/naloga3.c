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

// po potrebi dopolnite ...

bool zeUporabljeno(int stevilo, int* zeUporabljena, int indeks){
    for(int i = 0; i < indeks; i++){
        if(zeUporabljena[i] == stevilo){
            return true;
        }
    }
    return false;
}

int nacinov(int a, int b, int* zeUporabljena, int indeks, int n, int m){

    if(n == 1){
        // printf("%d %d\n", a, b);
        return 1;
    }

    zeUporabljena[indeks++] = a;
    zeUporabljena[indeks++] = b;

    int nacinovv = 0;
    for(int a = 1; a < m; a++){
        for(int b = 1; b < a; b++){
            if(n % (a+b) == 0 && a + b <= m && !zeUporabljeno(a, zeUporabljena, indeks) && !zeUporabljeno(b, zeUporabljena, indeks)){
                nacinovv += nacinov(a, b, zeUporabljena, indeks, n/(a+b), m);
            }
        }
    }

    return nacinovv;
}

int main() {
    
    int n, m;
    scanf("%d %d", &n, &m);

    int* zeUporabljena = malloc(5000*sizeof(int));

    printf("%d\n", nacinov(0, 0, zeUporabljena, 0, n, m));

    return 0;
}