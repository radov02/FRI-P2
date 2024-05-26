
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int stevil = 0;

void izpis(int stevilo, int stevk){
    for(int i = 0; i < stevk; i++){
        int stevka = stevilo / pow(10, stevk - i - 1);
        printf("%d", stevka);
        stevilo = stevilo - stevka*pow(10, stevk - i - 1);
    }
    printf("\n");
}

void izpisi(int stevilo, int stevka, int n, int k, int m){

    if(m == stevil-3){
        return;
    }
    if(stevilo >= pow(10, n-1)){
        stevil++;
        izpis(stevilo, n);
        return;
    }
    if(stevilo >= pow(10, n)){
        return;
    }

    stevilo = stevilo*10 + stevka;

    for(int i = 0; i < 10; i++){
        if(abs(i - stevilo % 10) == k){
            izpisi(stevilo, i, n, k, m);
        }
    }
}

int main() {
    
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    for(int i = 1; i < 10; i++){
        izpisi(0, i, n, k, m);
    }

    return 0;
}
