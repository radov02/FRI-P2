#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void izpisVerige(int* veriga, int velikost){
    for(int i = 0; i < velikost; i++){
        if(i < velikost-1){
            printf("%d->", veriga[i]);
        }
        else{
            printf("%d", veriga[i]);
        }
    }
    printf("\n");
}

double razdalja(int* kamen1, int* kamen2){
    double dx2 = (kamen1[0] - kamen2[0])*(kamen1[0] - kamen2[0]);
    double dy2 = (kamen1[1] - kamen2[1])*(kamen1[1] - kamen2[1]);
    return sqrt(dx2+dy2);
}

void izpisi(int* veriga, int indeksVeriga, double prejsnjaOddaljenost, int trenutniKamen, int** kamni, int n, int K){
    if(trenutniKamen == n-1){
        veriga[indeksVeriga] = trenutniKamen;
        izpisVerige(veriga, indeksVeriga+1);
        return;
    }

    veriga[indeksVeriga] = trenutniKamen;

    for(int i = 1; i < n; i++){
        double razdaljaKamnov = razdalja(kamni[trenutniKamen], kamni[i]);
        double oddaljenost = razdalja(kamni[i], kamni[n-1]);
        if(razdaljaKamnov <= K && prejsnjaOddaljenost > oddaljenost){
            izpisi(veriga, indeksVeriga+1, oddaljenost, i, kamni, n, K);
        }
    }
}

int main(){

    int n, K;
    scanf("%d %d", &n, &K);

    int** kamni = malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++){
        kamni[i] = (int*)malloc(2*sizeof(int));
        scanf("%d %d", &kamni[i][0], &kamni[i][1]);
    }
    int* veriga = calloc(n, sizeof(int));

    izpisi(veriga, 0, razdalja(kamni[0], kamni[n-1]), 0, kamni, n, K);

    return 0;
}