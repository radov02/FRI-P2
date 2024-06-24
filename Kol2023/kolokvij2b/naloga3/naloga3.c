
/*
 * Zagon testne skripte ("sele potem, ko ste prepri"cani, da program deluje!):
 *
 * export name=naloga3
 * make test
 *
 * Testni primeri:
 * 02--06: graf je acikli"cen
 * 01, 07--10: splo"sni
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

void izpis(int* zeObiskana, int indeks){
    for(int i = 0; i < indeks; i++){
        if(i < indeks-1){
            printf("%d->", zeObiskana[i]);
        }
        else{
            printf("%d", zeObiskana[i]);
        }
    }
    printf("\n");
}

bool zeObiskano(int vozlisce, int* zeObiskana, int indeks){
    for(int i = 0; i < indeks; i++){
        if(vozlisce == zeObiskana[i]){
            return true;
        }
    }
    return false;
}

void izpisi(int trenutno, int trenutnaVsota, int** povezave, int* zeObiskana, int indeks, int n, int m, int K){

    if(trenutno == n-1){
        zeObiskana[indeks++] = trenutno;
        izpis(zeObiskana, indeks);
        return;
    }

    // printf("%d\n", trenutno);

    zeObiskana[indeks++] = trenutno;

    for(int i = 0; i < m; i++){
        if(povezave[i][0] == trenutno && trenutnaVsota + povezave[i][2] <= K && !zeObiskano(povezave[i][1], zeObiskana, indeks)){
            izpisi(povezave[i][1], trenutnaVsota + povezave[i][2], povezave, zeObiskana, indeks, n, m, K);
        }
    }
}

int main() {

    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);
    int** povezave = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++){
        povezave[i] = malloc(3*sizeof(int));
        scanf("%d %d %d", &povezave[i][0], &povezave[i][1], &povezave[i][2]);
    }
    int* zeObiskana = malloc(n*sizeof(int));

    izpisi(0, 0, povezave, zeObiskana, 0, n, m, K);

    return 0;
}
