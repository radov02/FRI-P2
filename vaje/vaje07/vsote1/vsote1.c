#include <stdio.h>

int izpisi(int n, int k, int trenutnaVsota){
    if(trenutnaVsota >= n){
        return trenutnaVsota;
    }

    for(int i = 1; i <= k; i++){
        trenutnaVsota += i;
        return izpisi(n, i, trenutnaVsota);
    }
}

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    int rezultat = izpisi(n, k, 0);
    printf("%d\n", rezultat);
}