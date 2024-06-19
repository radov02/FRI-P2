
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

void izpis(int* pot, int indeksPot){
    for(int i = 0; i < indeksPot; i++){
        if(i < indeksPot-1) {
            printf("%d->", pot[i]);
        }
        else{
            printf("%d", pot[i]);
        }
    }
    printf("\n");
}

bool zeObiskano(int vozlisce, int* pot, int indeksPot){
    for(int i = 0; i < indeksPot; i++){
        if(pot[indeksPot] == vozlisce){
            return true;
        }
    }
    return false;
}

void izpisi(int trenutnoVozlisce, int trenutnaVsota, int* pot, int indeksPot, int** povezave, int n, int m, int K){

    if(trenutnoVozlisce == n-1){
        pot[indeksPot++] = trenutnoVozlisce;
        izpis(pot, indeksPot);
        return;
    }

    printf("%d\n", trenutnoVozlisce);
    pot[indeksPot++] = trenutnoVozlisce;

    for(int i = 0; i < m; i++){
        
        if(povezave[i][0] == trenutnoVozlisce && trenutnaVsota + povezave[i][2] <= K && !zeObiskano(povezave[i][1], pot, indeksPot)){
            izpisi(povezave[i][1], trenutnaVsota + povezave[i][2], pot, indeksPot, povezave, n, m, K);
        }
    }
    printf("    %d\n", trenutnoVozlisce);
}

int main() {
   
    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);
    int** povezave = malloc(m*sizeof(int*));
    for(int i = 0; i < m; i++){
        povezave[i] = malloc(3*sizeof(int));
        scanf("%d %d %d", &povezave[i][0], &povezave[i][1], &povezave[i][2]);
    }
    int* pot = calloc(n, sizeof(int));

    izpisi(0, 0, pot, 0, povezave, n, m, K);

    return 0;
}
