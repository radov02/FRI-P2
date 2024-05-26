
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

bool zeObiskano(int vozlisce, int* vozliscaPoti, int indeksVozliscaPoti){
    for(int i = 0; i < indeksVozliscaPoti; i++){
        if(vozlisce == vozliscaPoti[i]){
            return true;
        }
    }
    return false;
}

void izpisiPoti(int* vozliscaPoti, int velikostPoti){
    for(int i = 0; i < velikostPoti; i++){
        if(i < velikostPoti-1){
            printf("%d->", vozliscaPoti[i]);
        }
        else{
            printf("%d", vozliscaPoti[i]);
        }
    }
    printf("\n");
}

void izpisi(int* vozliscaPoti, int indeksVozliscaPoti, int trenutno, int vsotaUtezi, int** povezave, int n, int m, int K){

    if(trenutno == n-1){
        vozliscaPoti[indeksVozliscaPoti] = n-1;
        izpisiPoti(vozliscaPoti, indeksVozliscaPoti+1);
        return;
    }

    vozliscaPoti[indeksVozliscaPoti] = trenutno;

    for(int i = 0; i < m; i++){
        if(povezave[i][0] == trenutno && vsotaUtezi + povezave[i][2] <= K && !zeObiskano(povezave[i][1], vozliscaPoti, indeksVozliscaPoti)){
            izpisi(vozliscaPoti, indeksVozliscaPoti+1, povezave[i][1], vsotaUtezi + povezave[i][2], povezave, n, m, K);
        }
    }
}


int main() {

    int n, m, K;
    scanf("%d %d %d", &n, &m, &K);

    int** povezave = calloc(m, sizeof(int*));

    for(int i = 0; i < m; i++){
        povezave[i] = calloc(3, sizeof(int));
        scanf("%d %d %d", &povezave[i][0], &povezave[i][1], &povezave[i][2]);
    }

    int* vozliscaPoti = calloc(n, sizeof(int));
    izpisi(vozliscaPoti, 0, 0, 0, povezave, n, m, K);

    return 0;
}
