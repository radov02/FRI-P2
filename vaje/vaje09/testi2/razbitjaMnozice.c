#include <stdio.h>
#include <stdlib.h>

void izpisi(int* tabela, int n){
    printf("{");
    for(int i = 0; i < n; i++){
        if(i < n-1){
            printf("%d, ", tabela[i]);
        }
        else{
            printf("%d}", tabela[i]);
        }
    }
    printf("\n");
}

void razbitja(int vsota, int trenutnaStevilka, int* mnozica, int indeksRazbitje, int* razbitje, int zacetnaVsota, int n){

    if(vsota == zacetnaVsota / 2){
        izpisi(razbitje, indeksRazbitje);
        return;
    }

    for(int i = trenutnaStevilka+1; i < n; i++){
        if(mnozica[trenutnaStevilka] + mnozica[i] <= zacetnaVsota/2){
            razbitje[indeksRazbitje] = mnozica[i];
            if(mnozica[0] == razbitje[0]){
                razbitja(vsota + mnozica[i], i, mnozica, indeksRazbitje+1, razbitje, zacetnaVsota, n);
            }
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int* mnozica = calloc(n, sizeof(int));
    int vsota = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &mnozica[i]);
        vsota += mnozica[i];
    }

    int* razbitje = calloc(n, sizeof(int));

    razbitja(0, -1, mnozica, 0, razbitje, vsota, n);

    return 0;
}