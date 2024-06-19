#include <stdio.h>
#include <stdlib.h>

void izpis(int* zaporedje, int indeks){
    for(int i = 0; i < indeks; i++){
        if(i < indeks-1){
            printf("%d + ", zaporedje[i]);
        }
        else{
            printf("%d\n", zaporedje[i]);
        }
    }
}

void izpisi(int stevilo, int* zaporedje, int indeks, int n, int k){

    if(n == 0){
        zaporedje[indeks++] = stevilo;
        izpis(zaporedje, indeks);
        return;
    }

    zaporedje[indeks++] = stevilo;

    for(int i = stevilo; i > 0; i--){
        if(n - i >= 0){
            izpisi(i, zaporedje, indeks, n-i, k);
        }
    }
}

int main(){

    int n, k;
    scanf("%d %d", &n, &k);

    int* zaporedje = malloc(n*sizeof(int));
    for(int i = k; i > 0; i--){
        izpisi(i, zaporedje, 0, n-i, k);
    }

    return 0;
}